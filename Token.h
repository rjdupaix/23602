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
    TokenType type;
    string description;
    int line;

public:
    Token(TokenType type, string description, int line);
    void toString();
    bool match(TokenType t);
    TokenType getType();
};

#endif // TOKEN_H

