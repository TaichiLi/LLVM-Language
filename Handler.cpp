//===----------------------------------------------------------------------===//
// Top-Level parsing and JIT Driver
//===----------------------------------------------------------------------===//

#include "Handler.h"
#include "Parser.h"
#include "AST.h"

LLVMContext TheContext;
std::unique_ptr<Module> TheModule;
std::map<std::string, std::unique_ptr<PrototypeAST>> FunctionProtos;

Handler::Handler() {
  parser = new Parser();
}

void Handler::InitializeModuleAndPassManager() {
  // Open a new module.
  TheModule = llvm::make_unique<Module>("my cool jit", TheContext);
}

void Handler::HandleDefinition() {
  if (auto FnAST = parser->ParseDefinition()) {
    if (auto *FnIR = FnAST->codegen()) {
      fprintf(stderr, "Read function definition:");
      FnIR->print(errs());
      fprintf(stderr, "\n");
    }
  } else {
    // Skip token for error recovery.
    parser->getNextToken();
  }
}

void Handler::HandleExtern() {
  if (auto ProtoAST = parser->ParseExtern()) {
    if (auto *FnIR = ProtoAST->codegen()) {
      fprintf(stderr, "Read extern: ");
      FnIR->print(errs());
      fprintf(stderr, "\n");
      FunctionProtos[ProtoAST->getName()] = std::move(ProtoAST);
    }
  } else {
    // Skip token for error recovery.
    parser->getNextToken();
  }
}

void Handler::HandleTopLevelExpression() {
  // Evaluate a top-level expression into an anonymous function.
  if (auto FnAST = parser->ParseTopLevelExpr()) {
    FnAST->codegen();
  } else {
    // Skip token for error recovery.
    parser->getNextToken();
  }
}

/// top ::= definition | external | expression | ';'
void Handler::MainLoop() {
  while (true) {
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