#include "Token.h"

Token::Token(TokenType type, std::string description, int line) : type(type), description(description), line(line) {}

void Token::toString() {
    cout << "(";
    switch (this->type) {
        case TokenType::COLON:
            cout << "COLON";
            break;
        case TokenType::COLON_DASH:
            cout << "COLON_DASH";
            break;
        case TokenType::COMMA:
            cout << "COMMA";
            break;
        case TokenType::PERIOD:
            cout << "PERIOD";
            break;
        case TokenType::Q_MARK:
            cout << "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            cout << "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            cout << "RIGHT_PAREN";
            break;
        case TokenType::MULTIPLY:
            cout << "MULTIPLY";
            break;
        case TokenType::ADD:
            cout << "ADD";
            break;
        case TokenType::ID:
            cout << "ID";
            break;
        case TokenType::STRING:
            cout << "STRING";
            break;
        case TokenType::COMMENT:
            cout << "COMMENT";
            break;
        case TokenType::SCHEMES:
            cout << "SCHEMES";
            break;
        case TokenType::FACTS:
            cout << "FACTS";
            break;
        case TokenType::QUERIES:
            cout << "QUERIES";
            break;
        case TokenType::RULES:
            cout << "RULES";
            break;
        case TokenType::END:
            cout << "EOF";
            break;
        case TokenType::UNDEFINED:
            cout << "UNDEFINED";
            break;
    }
    cout << ",\"" << description << "\"," << line << ")" << std::endl;
}

bool Token::match(TokenType t) {
    return (t == this->type);
}

TokenType Token::getType() {
    return this->type;
}