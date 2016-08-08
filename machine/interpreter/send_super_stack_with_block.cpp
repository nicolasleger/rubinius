#include "instructions/send_super_stack_with_block.hpp"

namespace rubinius {
  namespace interpreter {
    intptr_t send_super_stack_with_block(STATE, CallFrame* call_frame, intptr_t const opcodes[]) {
      intptr_t literal = argument(0);
      intptr_t count = argument(1);

      instructions::send_super_stack_with_block(state, call_frame, literal, count);

      call_frame->next_ip(instructions::data_send_super_stack_with_block.width);
      return ((Instruction)opcodes[call_frame->ip()])(state, call_frame, opcodes);
    }
  }
}
