#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <iostream>

using std::string;
using std::cout;

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    ID,
    STRING,
    COMMENT,
    SCHEMES,
    FACTS,
    QUERIES,
    RULES,
    END,
    UNDEFINED
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType type;
    string description;
    int line;

public:
    Token(TokenType type, string description, int line);
    string toString();

    // TODO: add other needed methods
};

#endif // TOKEN_H

