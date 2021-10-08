#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"
#include "Parser.h"

class Lexer
{
private:
    std::vector<Automaton*>* automata;
    std::vector<Token*>* tokens;

    void CreateAutomata();

public:
    Lexer()
    {
        tokens = new std::vector<Token*>();
        automata = new std::vector<Automaton*>();
        CreateAutomata();
    }
    ~Lexer();

    void Run(std::string& input);

    std::vector<Token*>* ReturnTokens();

};

#endif

