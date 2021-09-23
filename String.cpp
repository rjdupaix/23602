#include "String.h"

void String::S0(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void String::S1(const std::string &input) {

    //TODO: CORRECT THIS FUNCTION SO THAT IT WILL DEAL WITH THE END OF A FILE
    if (input[index] == '\n') { ++newLinesInToken; }
    if (index == static_cast<int>(input.size() - 1)) {
        this->type = TokenType::UNDEFINED;
        inputRead++;
        return;
    }
    if ((input[index] == '\'') && (input[index + 1] == '\'')) {
        inputRead += 2;
        index += 2;
        S1(input);
    }
    else if (input[index] == '\'') {
        inputRead++;
    }

    else {
        inputRead++;
        index++;
        S1(input);
    }
}