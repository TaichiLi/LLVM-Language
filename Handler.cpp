//===----------------------------------------------------------------------===//
// Top-Level parsing
//===----------------------------------------------------------------------===//

#include "Handler.h"
#include "Parser.h"
#include <cstdio>

Handler::Handler()
{
  parser = new Parser();
}

void Handler::HandleDefinition() {
  if (parser->ParseDefinition()) {
    fprintf(stderr, "Parsed a function definition.\n");
  } else {
    // Skip token for error recovery.
    parser->getNextToken();
  }
}

void Handler::HandleExtern() {
  if (parser->ParseExtern()) {
    fprintf(stderr, "Parsed an extern\n");
  } else {
    // Skip token for error recovery.
    parser->getNextToken();
  }
}

void Handler::HandleTopLevelExpression() {
  // Evaluate a top-level expression into an anonymous function.
  if (parser->ParseTopLevelExpr()) {
    fprintf(stderr, "Parsed a top-level expr\n");
  } else {
    // Skip token for error recovery.
    parser->getNextToken();
  }
}

/// top ::= definition | external | expression | ';'
void Handler::MainLoop() {
  while (true) {
    fprintf(stderr, "ready> ");
    switch (parser->getCurTok()) {
    case tok_eof:
      return;
    case ';': // ignore top-level semicolons.
      parser->getNextToken();
      break;
    case tok_def:
      HandleDefinition();
      break;
    case tok_extern:
      HandleExtern();
      break;
    default:
      HandleTopLevelExpression();
      break;
    }
  }
}