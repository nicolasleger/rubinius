#include "instructions.hpp"

#include "class/call_site.hpp"

namespace rubinius {
  namespace instructions {
    inline bool send_method(STATE, CallFrame* call_frame, intptr_t literal) {
      Object* recv = stack_top();
      CallSite* call_site = reinterpret_cast<CallSite*>(literal);

      Arguments args(call_site->name(), recv, cNil, 0, 0);

      (void)stack_pop();

      call_frame->return_value = call_site->execute(state, args);

      state->vm()->checkpoint(state);

      CHECK_AND_PUSH(call_frame->return_value);
    }
  }
}
