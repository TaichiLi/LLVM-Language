#ifndef LOGGER_H
#define LOGGER_H

#include "AST.h"
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
#include <memory>

class ExprAST;
class PrototypeAST;
class Logger
{
public:
    std::unique_ptr<ExprAST> LogError(const char *Str);
    std::unique_ptr<PrototypeAST> LogErrorP(const char *Str);
    llvm::Value* LogErrorV(const char *Str);
};

#endif