/* THIS FILE IS AUTOMATICALLY GENERATED. PLEASE DO NOT MODIFY. */
#include <array>
#include <functional>

#include "helper.h"
#include "instructions_impl.h"

namespace instructions {
  static const std::array<
    std::function<int(Instruction,
                      const std::shared_ptr<LunaStack>&,
                      const std::vector<chunk::Literal>&)>,
    83>
    s_execution = {
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto value = p_stack->Get(((p_ins >> 7) & 0xFF));
        const auto pos = ((p_ins >> 16) & 0xFF);
        p_stack->Set(pos, value);
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        p_stack->Set(((p_ins >> 7) & 0xFF),
                     (((p_ins >> 15) & 0x1FFFF) - 0xFFFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        p_stack->Set(((p_ins >> 7) & 0xFF),
                     static_cast<double>((((p_ins >> 15) & 0x1FFFF) - 0xFFFF)));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        p_stack->Push(FromLiteral(p_const[((p_ins >> 15) & 0x1FFFF)]));
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        p_stack->Set(((p_ins >> 7) & 0xFF), false);
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        p_stack->Set(((p_ins >> 7) & 0xFF), true);
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        p_stack->Push(nullptr);
        for (int i = 0; i <= ((p_ins >> 16) & 0xFF); ++i) {
          p_stack->Copy(-1, i);
        }
        p_stack->Pop();
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto temp = p_stack->Get(((p_ins >> 16) & 0xFF));
        if (temp.index() != LunaType::LUNA_TABLE)
          ;
        const auto table = std::get<LunaType::LUNA_TABLE>(temp);
        const auto key = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto value = table->Get(key);
        p_stack->Set(((p_ins >> 7) & 0xFF), value);
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto temp = p_stack->Get(((p_ins >> 7) & 0xFF));
        if (temp.index() != LunaType::LUNA_TABLE)
          ;
        const auto table = std::get<LunaType::LUNA_TABLE>(temp);
        const auto key = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto value =
          GetFromStackOrConst(p_stack, p_const, ((p_ins >> 24) & 0xFF));
        table->Set(key, value);
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        p_stack->Set(((p_ins >> 7) & 0xFF), CreateTable());
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res = CalcArith(math::ArithOperator::ADD, p1, p2);
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res = CalcArith(math::ArithOperator::SUB, p1, p2);
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res = CalcArith(math::ArithOperator::MUL, p1, p2);
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res = Mod(p1, p2);
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res = CalcArith(math::ArithOperator::POW, p1, p2);
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res = CalcArith(math::ArithOperator::DIV, p1, p2);
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res = CalcArith(math::ArithOperator::I_DIV, p1, p2);
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto res = Neg(p);
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto res = Not(p);
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto res = Len(p);
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        auto res = p_stack->Get(((p_ins >> 7) & 0xFF));
        for (int i = ((p_ins >> 7) & 0xFF) + 1;
             i < ((p_ins >> 7) & 0xFF) + ((p_ins >> 16) & 0xFF);
             ++i) {
          const auto p = p_stack->Get(i);
          res = Concat(res, p);
        }
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        return (((p_ins >> 7) & 0x1FFFFFF) - 0xFFFFFF) + 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto a = ((p_ins >> 7) & 0xFF);
        const auto b = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto c = p_stack->Get(((p_ins >> 24) & 0xFF));
        return (math::Compare(math::ComOperator::EQ, b, c) == a) ? 1 : 2;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto a = ((p_ins >> 7) & 0xFF);
        const auto b = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto c = p_stack->Get(((p_ins >> 24) & 0xFF));
        return (math::Compare(math::ComOperator::LT, b, c) == a) ? 1 : 2;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto a = ((p_ins >> 7) & 0xFF);
        const auto b = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto c = p_stack->Get(((p_ins >> 24) & 0xFF));
        return (math::Compare(math::ComOperator::LE, b, c) == a) ? 1 : 2;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto a = p_stack->Get(((p_ins >> 7) & 0xFF));
        const auto c = ((p_ins >> 24) & 0xFF);
        return (ToBoolean(a) != ToBoolean(c)) ? 2 : 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto b = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto c = ((p_ins >> 24) & 0xFF);
        if (ToBoolean(b) != ToBoolean(c)) {
          p_stack->Set(((p_ins >> 7) & 0xFF), b);
          return 1;
        } else {
          return 2;
        }
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        UpdateForCount(p_stack, ((p_ins >> 7) & 0xFF));
        return (ShouldSkipForLoop(p_stack, ((p_ins >> 7) & 0xFF)))
          ? 1
          : 1 - ((p_ins >> 15) & 0x1FFFF);
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        return (ShouldSkipForLoop(p_stack, ((p_ins >> 7) & 0xFF)))
          ? 1
          : 1 + ((p_ins >> 15) & 0x1FFFF);
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) { return 1; },
  };
  int Execute(Instruction p_ins,
              const std::shared_ptr<LunaStack>& p_stack,
              const std::vector<chunk::Literal>& p_const) {
    return ((p_ins & 0x7F) < s_execution.size())
      ? s_execution[(p_ins & 0x7F)](p_ins, p_stack, p_const)
      : 1;
  }
} // namespace instructions
