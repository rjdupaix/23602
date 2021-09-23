#include "ID.h"

void ID::S0(const std::string &input) {
    if (std::isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void ID::S1(const std::string &input) {
    if (std::isalpha(input[index]) || std::isdigit(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
}