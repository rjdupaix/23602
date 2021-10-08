#ifndef AUTOMATON_H
#define AUTOMATON_H
#include "Token.h"

class Automaton
{
protected:
    int inputRead = 0;
    int newLines = 0;
    int newLinesInToken = 0;
    int index = 0;
    TokenType type;

public:
    Automaton() : Automaton(TokenType::UNDEFINED) {}

    Automaton(TokenType type) { this->type = type; }

    int Start(const std::string& input) {
        newLines = 0;
        newLinesInToken = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }

    virtual void S0(const std::string& input) = 0;

    void Serr() {
        inputRead = 0;
    }

    virtual Token* CreateToken(std::string input, int lineNumber) { return new Token(type, input, lineNumber); }

    int NewLinesRead() const { return newLines; }

    int NewLinesInToken() const { return newLinesInToken; }
};

#endif

