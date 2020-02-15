//===----------------------------------------------------------------------===//
// Main driver code.
//===----------------------------------------------------------------------===//

#include "Parser.h"
#include "Lexer.h"

int main() {
  // Install standard binary operators.
  // 1 is lowest precedence.
  Parser parser;
  parser.setBinopPrecedence('<', 10);
  parser.setBinopPrecedence('+', 20);
  parser.setBinopPrecedence('-', 20);
  parser.setBinopPrecedence('*', 40); // highest.

  // Prime the first token.
  fprintf(stderr, "ready> ");
  parser.getNextToken();

  // Run the main "interpreter loop" now.
  parser.MainLoop();

  return 0;
}
