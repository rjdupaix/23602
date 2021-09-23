#ifndef ID_H
#define ID_H

#include "Automaton.h"

class ID : public Automaton
{
private:
    void S1(const std::string& input);

public:
    ID() : Automaton(TokenType::ID) {}

    void S0(const std::string& input);
};

#endif
