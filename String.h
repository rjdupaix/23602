#ifndef STRING_H
#define STRING_H

#include "Automaton.h"

class String : public Automaton
{
private:
    void S1(const std::string& input);

public:
    String() : Automaton(TokenType::STRING) {}

    void S0(const std::string& input);
};

#endif
