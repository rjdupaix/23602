#ifndef MULTI_COMMENT_H
#define MULTI_COMMENT_H

#include "Automaton.h"

class Multi_Comment : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);


public:
    Multi_Comment() : Automaton(TokenType::COMMENT) {}

    void S0(const std::string& input);
};

#endif //MULTI_COMMENT_H
