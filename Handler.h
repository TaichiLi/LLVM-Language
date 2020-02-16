//===----------------------------------------------------------------------===//
// Top-Level parsing
//===----------------------------------------------------------------------===//

#ifndef HANDLER_H
#define HANDLER_H

#include "Parser.h"

extern LLVMContext TheContext;
extern std::unique_ptr<Module> TheModule;
extern std::unique_ptr<legacy::FunctionPassManager> TheFPM;
extern std::unique_ptr<KaleidoscopeJIT> TheJIT;
extern std::map<std::string, std::unique_ptr<PrototypeAST>> FunctionProtos;

class Handler
{
    private:
        Parser *parser;

    public:
        Handler();
        Parser *getParser() { return parser; }
        void InitializeModuleAndPassManager();
        void HandleDefinition();
        void HandleExtern();
        void HandleTopLevelExpression();
        void MainLoop();
};

#endif