//===----------------------------------------------------------------------===//
// Top-Level parsing
//===----------------------------------------------------------------------===//

#ifndef HANDLER_H
#define HANDLER_H

#include "Parser.h"

class Handler
{
    private:
        Parser *parser;

    public:
        Handler();
        Parser *getParser() { return parser; }
        void HandleDefinition();
        void HandleExtern();
        void HandleTopLevelExpression();
        void MainLoop();
};

#endif