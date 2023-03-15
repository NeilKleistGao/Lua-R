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
  | InstABC (_, _) | InstABx (_, _) -> "((p_ins >> 7) & 0xFF)"
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
  | InstAsBx(_, _) -> "((p_ins >> 15) & 0x1FFFF)"
  | _ -> raise (WrongField "no field sBx found.");;

let ax ins = match ins with
  | InstAx(_, _) -> "((p_ins >> 7) & 0x1FFFFFF)"
  | _ -> raise (WrongField "no field Ax found.");;

let sj ins = match ins with
  | InstsJ(_, _) -> "((p_ins >> 7) & 0x1FFFFFF)"
  | _ -> raise (WrongField "no field sJ found.");;

let fprintf params =
  match params with
    | [] -> ""
    | format :: values ->
      (List.fold_left (fun r s -> r ^ "," ^ s) ("fprintf(p_fp, \"%s" ^ format ^ "\\n\", p_indent.c_str()") values) ^
      ");";;

let rec pretty_print_rec i lst res = 
  match lst with
    | [] -> res
    | head :: tail ->
      pretty_print_rec (i + 1) tail (res ^ "case " ^ (string_of_int i) ^ ": " ^ (fprintf head) ^ "break;\n");;

let pretty_print lst =
  "#include \"instructions_pretty_printer.h\"\n" ^
  "\n" ^
  "namespace instructions {\n" ^
  "void PrintInstruction(FILE* p_fp,\n" ^
  "Instruction p_ins," ^
  "const std::string& p_indent) {\n" ^
  "switch" ^ op_ins ^ "{\n" ^
  (pretty_print_rec 0 lst "") ^
  "default: fprintf(p_fp, \"%sInvalid Op Code %d\\n\", p_indent.c_str(), p_ins);\n" ^
  "}\n" ^
  "}\n" ^
  "}\n";;

let lambda lst =
  (List.fold_left (fun r s -> r ^ s ^ "\n") ("[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){\n") lst) ^ "}";;

let rec execute_rec lst res =
  match lst with
    | [] -> res
    | head :: tail -> (execute_rec tail (res ^ (lambda head) ^ ",\n"));;

let execute lst =
  "#include <array>\n" ^
  "#include <functional>\n" ^
  "#include \"instructions_impl.h\"\n" ^
  "namespace instructions {\n" ^
  "static const std::array<std::function<int(Instruction, const std::shared_ptr<LunaStack>&)>," ^ (string_of_int (List.length lst)) ^ ">s_execution = {\n" ^
  (execute_rec lst "") ^ "};\n" ^
  "int Execute(Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack) {\n" ^
  "return s_execution[" ^ op_ins ^ "](p_ins, p_stack);\n" ^
  "}\n" ^
  "}\n";;

(* put instructions in order *)
(* TODO: add more check for C++ AST *)
let instructions = [
  InstABC ( (* 0 *)
    (fun ins -> ["Move"]),
    (fun ins -> [
      "const auto value = p_stack->Get(" ^ a(ins) ^ ");";
      "const auto pos = " ^ b(ins) ^ ";";
      "if (value.has_value()) { p_stack->Set(pos, value.value()); }"; (* TODO: throw *)
      "return 1;"
    ])
  );
  InstAsBx (
    (fun ins -> ["Load I"]),
    (fun ins -> ["return 1;"])
  );
  InstAsBx (
    (fun ins -> ["Load F"]),
    (fun ins -> ["return 1;"])
  );
  InstABx (
    (fun ins -> ["Load K"]),
    (fun ins -> ["return 1;"])
  );
  InstABx (
    (fun ins -> ["Load KX"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 5 *)
    (fun ins -> ["Load False"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["L False Skip"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Load True"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Load Nil"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Get Up Value"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 10 *)
    (fun ins -> ["Set Up Value"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Get Table Up"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Get Table"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Get I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Get Field"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 15 *)
    (fun ins -> ["Set Table Up"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Set Table"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Set I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Set Field"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["New Table"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 20 *)
    (fun ins -> ["Self"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Add I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Add K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Sub K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Mul K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 25 *)
    (fun ins -> ["Mod K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Pow K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Div K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["I Div K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Bit And K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 30 *)
    (fun ins -> ["Bit Or K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Bit Xor K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Shift Right I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Shift Left I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Add"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 35 *)
    (fun ins -> ["Sub"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Mul"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Mod"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Pow"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Div"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 40 *)
    (fun ins -> ["I Div"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Bit And"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Bit Or"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Bit Xor"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Shift Left"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 45 *)
    (fun ins -> ["Shift Right"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["MM Bin"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["MM Bin I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["MM Bin K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["UNM"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 50 *)
    (fun ins -> ["Bit Not"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Not"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Len"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Concat"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Close"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 55 *)
    (fun ins -> ["TBC"]),
    (fun ins -> ["return 1;"])
  );
  InstsJ (
    (fun ins -> ["Jump"]),
    (fun ins -> ["return " ^ sj(ins) ^ ";"])
  );
  InstABC (
    (fun ins -> ["Equal"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Less Than"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Less Equal"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 60 *)
    (fun ins -> ["Equal K"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Equal I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Less Than I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Less Equal I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Greater Than I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 65 *)
    (fun ins -> ["Greater Equal I"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Test"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Test Set"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Call"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Tail Call"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 70 *)
    (fun ins -> ["Return %d, %d"; (a ins); (b ins)]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Return 0"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Return 1"]),
    (fun ins -> ["return 1;"])
  );
  InstABx (
    (fun ins -> ["For Loop"]),
    (fun ins -> ["return 1;"])
  );
  InstABx (
    (fun ins -> ["For Prepare"]),
    (fun ins -> ["return 1;"])
  );
  InstABx ( (* 75 *)
    (fun ins -> ["T For Prepare"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["T For Call"]),
    (fun ins -> ["return 1;"])
  );
  InstABx (
    (fun ins -> ["T For Loop"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Set List"]),
    (fun ins -> ["return 1;"])
  );
  InstABx (
    (fun ins -> ["Closure"]),
    (fun ins -> ["return 1;"])
  );
  InstABC ( (* 80 *)
    (fun ins -> ["Variable Arguments"]),
    (fun ins -> ["return 1;"])
  );
  InstABC (
    (fun ins -> ["Variable Arguments Prepare"]),
    (fun ins -> ["return 1;"])
  );
  InstAx (
    (fun ins -> ["Extra Arguments"]),
    (fun ins -> ["return 1;"])
  );
];;

let pretty_print_cpp = (pretty_print
  (List.map (fun ins -> match ins with
    | InstABC(pp, _) as ins -> pp ins
    | InstABx (pp, _) as ins -> pp ins
    | InstAsBx(pp, _) as ins -> pp ins
    | InstAx(pp, _) as ins -> pp ins
    | InstsJ(pp, _) as ins -> pp ins
  ) instructions));;

let impl_cpp = (execute
(List.map (fun ins -> match ins with
  | InstABC(_, stmts) as ins -> stmts ins
  | InstABx (_, stmts) as ins -> stmts ins
  | InstAsBx(_, stmts) as ins -> stmts ins
  | InstAx(_, stmts) as ins -> stmts ins
  | InstsJ(_, stmts) as ins -> stmts ins
) instructions));;

let filename = "test/cpp/instructions_pretty_printer.cc" in
  let oc = open_out filename in
    Printf.fprintf oc "%s\n" pretty_print_cpp;
    close_out oc;;

let filename = "main/luna/instructions/instructions_impl.cc" in
  let oc = open_out filename in
    Printf.fprintf oc "%s\n" impl_cpp;
    close_out oc;;
