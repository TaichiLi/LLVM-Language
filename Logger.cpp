//===----------------------------------------------------------------------===//
// Logger
//===----------------------------------------------------------------------===//

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