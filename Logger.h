//===----------------------------------------------------------------------===//
// Logger
//===----------------------------------------------------------------------===//

#ifndef LOGGER_H
#define LOGGER_H

#include "AST.h"
#include <memory>

class Logger
{
public:
    std::unique_ptr<ExprAST> LogError(const char *Str);
    std::unique_ptr<PrototypeAST> LogErrorP(const char *Str);
};

#endif