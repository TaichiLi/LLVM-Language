//===----------------------------------------------------------------------===//
// Logger
//===----------------------------------------------------------------------===//

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "Logger.h"
#include "AST.h"
#include <memory>

/// LogError* - These are little helper functions for error handling.
std::unique_ptr<ExprAST> Logger::LogError(const char *Str) {
  fprintf(stderr, "Error: %s\n", Str);
  return nullptr;
}
std::unique_ptr<PrototypeAST> Logger::LogErrorP(const char *Str) {
  LogError(Str);
  return nullptr;
}

llvm::Value* Logger::LogErrorV(const char *Str) {
  LogError(Str);
  return nullptr;
}