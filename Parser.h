//===----------------------------------------------------------------------===//
// Parser
//===----------------------------------------------------------------------===//

#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include "AST.h"
#include <memory>
#include <map>

class Parser
{
private:
/// CurTok/getNextToken - Provide a simple token buffer.  CurTok is the current
/// token the parser is looking at.  getNextToken reads another token from the
/// lexer and updates CurTok with its results.
    Lexer lexer;
    int CurTok;

/// BinopPrecedence - This holds the precedence for each binary operator that is
/// defined.
    std::map<char, int> BinopPrecedence;
public:
    std::map<char, int> getBinopPrecedence() { return BinopPrecedence; }
    void setBinopPrecedence(char key, int value) { BinopPrecedence[key] = value; }
    int getNextToken() { return CurTok = lexer.gettok(); }
    int GetTokPrecedence();
    std::unique_ptr<ExprAST> LogError(const char *Str);
    std::unique_ptr<PrototypeAST> LogErrorP(const char *Str);
    std::unique_ptr<ExprAST> ParseExpression();
    std::unique_ptr<ExprAST> ParseNumberExpr();
    std::unique_ptr<ExprAST> ParseParenExpr();
    std::unique_ptr<ExprAST> ParseIdentifierExpr();
    std::unique_ptr<ExprAST> ParsePrimary();
    std::unique_ptr<ExprAST> ParseBinOpRHS(int ExprPrec, std::unique_ptr<ExprAST> LHS);
    std::unique_ptr<PrototypeAST> ParsePrototype();
    std::unique_ptr<FunctionAST> ParseDefinition();
    std::unique_ptr<FunctionAST> ParseTopLevelExpr();
    std::unique_ptr<PrototypeAST> ParseExtern();
    void HandleDefinition();
    void HandleExtern();
    void HandleTopLevelExpression();
    void MainLoop();
};

#endif