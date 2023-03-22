(*
 * MIT License
 *
 * Copyright (c) 2023 Cunyuan(Holden) Gao
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *)

(* pretty_printer, execution *)
type instruction =
  | InstABC of (instruction -> string list) * (instruction -> string list)
  | InstABx of (instruction -> string list) * (instruction -> string list)
  | InstAsBx of (instruction -> string list) * (instruction -> string list)
  | InstAx of (instruction -> string list) * (instruction -> string list)
  | InstsJ of (instruction -> string list) * (instruction -> string list);;

exception WrongField of string;;

let op_ins = "(p_ins & 0x7F)";;

let a ins = match ins with
  | InstABC (_, _) | InstABx (_, _) | InstAsBx(_, _) -> "((p_ins >> 7) & 0xFF)"
  | _ -> raise (WrongField "no field a found.");;

let b ins = match ins with
  | InstABC(_, _) -> "((p_ins >> 16) & 0xFF)"
  | _ -> raise (WrongField "no field b found.");;

let c ins = match ins with
  | InstABC(_, _) -> "((p_ins >> 24) & 0xFF)"
  | _ -> raise (WrongField "no field c found.");;

let k ins = match ins with
  | InstABC(_, _) -> "((p_ins >> 15) & 1)"
  | _ -> raise (WrongField "no field k found.");;

let bx ins = match ins with
  | InstABx(_, _) -> "((p_ins >> 15) & 0x1FFFF)"
  | _ -> raise (WrongField "no field Bx found.");;

let sbx ins = match ins with
  | InstAsBx(_, _) -> "(((p_ins >> 15) & 0x1FFFF) - 0xFFFF)"
  | _ -> raise (WrongField "no field sBx found.");;

let ax ins = match ins with
  | InstAx(_, _) -> "((p_ins >> 7) & 0x1FFFFFF)"
  | _ -> raise (WrongField "no field Ax found.");;

let sj ins = match ins with
  | InstsJ(_, _) -> "(((p_ins >> 7) & 0x1FFFFFF) - 0xFFFFFF)"
  | _ -> raise (WrongField "no field sJ found.");;

let include_sys filename = "#include <" ^ filename ^ ">\n"
let include_user filename = "#include \"" ^ filename ^ "\"\n"

let fprintf params =
  match params with
    | [] -> ""
    | format :: values ->
      (List.fold_left (fun r s -> r ^ "," ^ s) ("fprintf(p_fp, \"%s " ^ format ^ "\\n\", p_indent.c_str()") values) ^
      ");";;

let rec pretty_print_rec i lst res = 
  match lst with
    | [] -> res
    | head :: tail ->
      pretty_print_rec (i + 1) tail (res ^ "case " ^ (string_of_int i) ^ ": " ^ (fprintf head) ^ "break;\n");;

let pretty_print lst =
  "/* THIS FILE IS AUTOMATICALLY GENERATED. PLEASE DO NOT MODIFY. */\n" ^
  (include_user "instructions_pretty_printer.h") ^
  "\n" ^
  "namespace instructions {\n" ^
  "void PrintInstruction(FILE* p_fp,\n" ^
  "Instruction p_ins," ^
  "const std::string& p_indent) {\n" ^
  "switch" ^ op_ins ^ "{\n" ^
  (pretty_print_rec 0 lst "") ^
  "default: fprintf(p_fp, \"%s Invalid Op Code %d\\n\", p_indent.c_str(), p_ins);\n" ^
  "}\n" ^
  "}\n" ^
  "}\n";;

let lambda lst =
  (List.fold_left (fun r s -> r ^ s ^ "\n")
    ("[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack, const std::vector<chunk::Literal>& p_const){\n") lst) ^ "}";;

let rec execute_rec lst res =
  match lst with
    | [] -> res
    | head :: tail -> (execute_rec tail (res ^ (lambda head) ^ ",\n"));;

let execute lst =
  "/* THIS FILE IS AUTOMATICALLY GENERATED. PLEASE DO NOT MODIFY. */\n" ^
  (include_sys "array") ^
  (include_sys "functional") ^
  "\n" ^
  (include_user "instructions_impl.h") ^
  (include_user "helper.h") ^
  "\n" ^
  "namespace instructions {\n" ^
  "static const std::array<std::function<int(Instruction, const std::shared_ptr<LunaStack>&, const std::vector<chunk::Literal>&)>," ^ (string_of_int (List.length lst)) ^ ">s_execution = {\n" ^
  (execute_rec lst "") ^ "};\n" ^
  "int Execute(Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack, const std::vector<chunk::Literal>& p_const) {\n" ^
  "return s_execution[" ^ op_ins ^ "](p_ins, p_stack, p_const);\n" ^
  "}\n" ^
  "}\n";;
