//===----------------------------------------------------------------------===//
// Main driver code.
//===----------------------------------------------------------------------===//

#include "Handler.h"

int main() {
  // Install standard binary operators.
  // 1 is lowest precedence.
  Handler handler = Handler();
  handler.getParser()->setBinopPrecedence('<', 10);
  handler.getParser()->setBinopPrecedence('+', 20);
  handler.getParser()->setBinopPrecedence('-', 20);
  handler.getParser()->setBinopPrecedence('*', 40); // highest.

  // Prime the first token.
  fprintf(stderr, "ready> ");
  handler.getParser()->getNextToken();

  // Run the main "interpreter loop" now.
  handler.MainLoop();

  return 0;
}
