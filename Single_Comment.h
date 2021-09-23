#ifndef SINGLE_COMMENT_H
#define SINGLE_COMMENT_H

#include "Automaton.h"

class Single_Comment : public Automaton
{
private:
    void S1(const std::string& input);

public:
    Single_Comment() : Automaton(TokenType::COMMENT) {}

    void S0(const std::string& input);
};

#endif