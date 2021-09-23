#ifndef FACTS_H
#define FACTS_H

#include "Automaton.h"

class Facts : public Automaton
{
private:
    void S1(const std::string& input);

    void S2(const std::string& input);

    void S3(const std::string& input);

    void S4(const std::string& input);

public:
    Facts() : Automaton(TokenType::FACTS) {}

    void S0(const std::string& input);
};

#endif
