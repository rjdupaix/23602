#include "Multi_Comment.h"

void Multi_Comment::S0(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void Multi_Comment::S1(const std::string &input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void Multi_Comment::S2(const std::string &input) {
    if (input[index] == '\n') {
        newLinesInToken++;
    }
    if (input[index] != '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void Multi_Comment::S3(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}