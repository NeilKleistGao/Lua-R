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
        if (value.has_value()) {
          p_stack->Set(pos, value.value());
        }
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
        for (int i = 0; i <= ((p_ins >> 16) & 0xFF); ++i) p_stack->Copy(-1, i);
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
        const auto res =
          CalcArith(math::ArithOperator::ADD, p1.value(), p2.value());
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res =
          CalcArith(math::ArithOperator::SUB, p1.value(), p2.value());
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res =
          CalcArith(math::ArithOperator::MUL, p1.value(), p2.value());
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res = Mod(p1.value(), p2.value());
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res =
          CalcArith(math::ArithOperator::POW, p1.value(), p2.value());
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res =
          CalcArith(math::ArithOperator::DIV, p1.value(), p2.value());
        p_stack->Push(res);
        p_stack->ReplaceWithTop(((p_ins >> 7) & 0xFF));
        return 1;
      },
      [](Instruction p_ins,
         const std::shared_ptr<LunaStack>& p_stack,
         const std::vector<chunk::Literal>& p_const) {
        const auto p1 = p_stack->Get(((p_ins >> 16) & 0xFF));
        const auto p2 = p_stack->Get(((p_ins >> 24) & 0xFF));
        const auto res =
          CalcArith(math::ArithOperator::I_DIV, p1.value(), p2.value());
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
        const auto res = Neg(p.value());
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
        const auto res = Not(p.value());
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
         const std::vector<chunk::Literal>& p_const) {
        return (((p_ins >> 7) & 0x1FFFFFF) - 0xFFFFFF) + 1;
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
  };
  int Execute(Instruction p_ins,
              const std::shared_ptr<LunaStack>& p_stack,
              const std::vector<chunk::Literal>& p_const) {
    return ((p_ins & 0x7F) < s_execution.size())
      ? s_execution[(p_ins & 0x7F)](p_ins, p_stack, p_const)
      : 1;
  }
} // namespace instructions
