#include "instructions/goto.hpp"

namespace rubinius {
  namespace interpreter {
    intptr_t goto_(STATE, CallFrame* call_frame, intptr_t const opcodes[]) {
      intptr_t location = argument(0);

      instructions::goto_(call_frame);
      call_frame->set_ip(location);

      call_frame->next_ip(instructions::data_goto.width);
      return ((Instruction)opcodes[call_frame->ip()])(state, call_frame, opcodes);
    }
  }
}