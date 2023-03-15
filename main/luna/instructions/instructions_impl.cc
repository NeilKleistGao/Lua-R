#include <array>
#include <functional>
#include "instructions_impl.h"
namespace instructions {
static const std::array<std::function<int(Instruction, const std::shared_ptr<LunaStack>&)>,83>s_execution = {
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
const auto value = p_stack->Get(((p_ins >> 7) & 0xFF));
const auto pos = ((p_ins >> 16) & 0xFF);
if (value.has_value()) { p_stack->Set(pos, value.value()); }
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return ((p_ins >> 7) & 0x1FFFFFF);
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
[](Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack){
return 1;
},
};
int Execute(Instruction p_ins, const std::shared_ptr<LunaStack>& p_stack) {
return s_execution[(p_ins & 0x7F)](p_ins, p_stack);
}
}

