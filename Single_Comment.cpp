#include "Single_Comment.h"

void Single_Comment::S0(const std::string &input) {
    if (input[index] == '#' && input[index + 1] != '|') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void Single_Comment::S1(const std::string &input) {
    if (index >= static_cast<int>(input.size())) {
        this->type = TokenType::UNDEFINED;
        return;
    }
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\n') {
        return;
    }
}