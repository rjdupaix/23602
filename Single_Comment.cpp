#include "Single_Comment.h"

//Single_Comment::Single_Comment() : Automaton(TokenType::COMMENT) {}

void Single_Comment::S0(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void Single_Comment::S1(const std::string &input) {
    if (index >= static_cast<int>(input.size())) { return; }
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\n') {
        return;
    }
}