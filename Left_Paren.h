#ifndef LEFT_PAREN_H
#define LEFT_PAREN_H

#include "Automaton.h"

class Left_ParenAutomaton : public Automaton
{
public:
    Left_ParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif