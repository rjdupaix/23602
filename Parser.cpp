#include "Parser.h"

void Parser::Parse() {
    for (int i = 0; i < this->tokens->size(); ++i) {
        if (this->tokens->at(i)->getType() == TokenType::COMMENT) {
            this->tokens->erase(this->tokens->begin() + i);
            --i;
        }
    }
    datalog(this->tokens);
}

void Parser::datalog(vector<Token*>*& tokens) {
    size_t index = 0;
    Token* t = tokens->at(index);
    if (DATALOGFIRST.find(t->getType()) != DATALOGFIRST.end()) {
        if (t->match(TokenType::SCHEMES)) {
            ++index;
            t = tokens->at(index);
            if (t->match(TokenType::COLON)) {
                ++index;
                scheme(tokens, index);
                schemeList(tokens, index);
                t = tokens->at(index);
                if (t->match(TokenType::FACTS)) {
                    ++index;
                    t = tokens->at(index);
                    if (t->match(TokenType::COLON)) {
                        ++index;
                        factList(tokens, index);
                        t = tokens->at(index);
                        if (t->match(TokenType::RULES)) {
                            ++index;
                            t = tokens->at(index);
                            if (t->match(TokenType::COLON)) {
                                ++index;
                                ruleList(tokens, index);
                                t = tokens->at(index);
                                if (t->match(TokenType::QUERIES)) {
                                    ++index;
                                    t = tokens->at(index);
                                    if (t->match(TokenType::COLON)) {
                                        ++index;
                                        query(tokens, index);
                                        queryList(tokens, index);
                                        t = tokens->at(index);
                                        if (t->match(TokenType::END)) {
                                            ++index;
                                            return;
                                        }
                                        else { throw t; }
                                    }
                                    else { throw t; }
                                }
                                else { throw t; }
                            }
                            else { throw t; }
                        }
                        else { throw t; }
                    }
                    else { throw t; }
                }
                else { throw t; }
            }
            else { throw t; }
        }
        else { throw t; }
    }
    else { throw t; }
}

void Parser::scheme(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (SCHEMEFIRST.find(t->getType()) != SCHEMEFIRST.end()) {

        if (t->match(TokenType::ID)) {
            ++index;
            t = tokens->at(index);
            if (t->match(TokenType::LEFT_PAREN)) {
                ++index;
                t = tokens->at(index);
                if (t->match(TokenType::ID)) {
                    ++index;
                    idList(tokens, index);
                    t = tokens->at(index);
                    if (t->match(TokenType::RIGHT_PAREN)) {
                        ++index;
                    }
                    else { throw t; }
                }
                else { throw t; }
            }
            else { throw t; }
        }
        else { throw t; }
    }
    else { throw t; }
}

void Parser::idList(vector<Token *>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (IDLISTFIRST.find(t->getType()) != IDLISTFIRST.end()) {
        if (t->match(TokenType::COMMA)) {
            ++index;
            t = tokens->at(index);
            if (t->match(TokenType::ID)) {

                ++index;
                idList(tokens, index);
            }
            else { throw t; }
        }
        else { throw t; }
    }
    else { return; }
}

void Parser::schemeList(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (SCHEMELISTFIRST.find(t->getType()) != SCHEMELISTFIRST.end()) {
        scheme(tokens, index);
        schemeList(tokens, index);
    }
    else { return; }
}

void Parser::factList(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (FACTLISTFIRST.find(t->getType()) != FACTLISTFIRST.end()) {
        fact(tokens, index);
        factList(tokens, index);
    }
    else { return; }
}

void Parser::fact(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (FACTFIRST.find(t->getType()) != FACTFIRST.end()) {
        if (t->match(TokenType::ID)) {
            ++index;
            t = tokens->at(index);
            if (t->match(TokenType::LEFT_PAREN)) {
                ++index;
                t = tokens->at(index);
                if (t->match(TokenType::STRING)) {
                    ++index;
                    stringList(tokens, index);
                    t = tokens->at(index);
                    if (t->match(TokenType::RIGHT_PAREN)) {
                        index++;
                        t = tokens->at(index);
                        if (t->match(TokenType::PERIOD)) {
                            ++index;
                        }
                        else { throw t; }
                    }
                    else { throw t; }
                }
                else { throw t; }
            }
            else { throw t; }
        }
        else { throw t; }
    }
    else { throw t; }
}

void Parser::stringList(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (STRINGLISTFIRST.find(t->getType()) != STRINGLISTFIRST.end()) {
        if (t->match(TokenType::COMMA)) {
            ++index;
            t = tokens->at(index);
            if (t->match(TokenType::STRING)) {
                ++index;
                stringList(tokens, index);
            }
            else { throw t; }
        }
        else { throw t; }
    }
    else { return; }
}

void Parser::ruleList(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (RULELISTFIRST.find(t->getType()) != RULELISTFIRST.end()) {
        rule(tokens, index);
        ruleList(tokens, index);
    }
    else { return; }
}

void Parser::rule(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (RULEFIRST.find(t->getType()) != RULEFIRST.end()) {
        headPredicate(tokens, index);
        t = tokens->at(index);
        if (t->match(TokenType::COLON_DASH)) {
            ++index;
            predicate(tokens, index);
            predicateList(tokens, index);
            t = tokens->at(index);
            if (t->match(TokenType::PERIOD)) {
                index++;
            }
            else { throw t; }
        }
        else { throw t; }
    }
    else { throw t; }
}

void Parser::headPredicate(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (HEADPREDICATEFIRST.find(t->getType()) != HEADPREDICATEFIRST.end()) {
        if (t->match(TokenType::ID)) {
            ++index;
            t = tokens->at(index);
            if (t->match(TokenType::LEFT_PAREN)) {
                ++index;
                t = tokens->at(index);
                if (t->match(TokenType::ID)) {
                    ++index;
                    idList(tokens, index);
                    t = tokens->at(index);
                    if (t->match(TokenType::RIGHT_PAREN)) {
                        ++index;
                    }
                    else { throw t; }
                }
                else { throw t; }
            }
            else { throw t; }
        }
        else { throw t; }
    }
    else { throw t; }
}

void Parser::predicate(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (PREDICATEFIRST.find(t->getType()) != PREDICATEFIRST.end()) {
        if (t->match(TokenType::ID)) {
            ++index;
            t = tokens->at(index);
            if (t->match(TokenType::LEFT_PAREN)) {
                ++index;
                parameter(tokens, index);
                parameterList(tokens, index);
                t = tokens->at(index);
                if (t->match(TokenType::RIGHT_PAREN)) {
                    ++index;
                }
                else { throw t; }
            }
            else { throw t; }
        }
        else { throw t; }
    }
    else { throw t; }
}

void Parser::predicateList(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (PREDICATELISTFIRST.find(t->getType()) != PREDICATELISTFIRST.end()) {
        if (t->match(TokenType::COMMA)) {
            ++index;
            predicate(tokens, index);
            predicateList(tokens, index);
        }
        else { throw t; }
    }
    else { return; }
}

void Parser::parameter(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (PARAMETERFIRST.find(t->getType()) != PARAMETERFIRST.end()) {
        if (t->match(TokenType::STRING)) {
            ++index;
        }
        else if (t->match(TokenType::ID)) {
            ++index;
        }
        else { throw t; }
    }
    else { throw t; }
}

void Parser::parameterList(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (PARAMETERLISTFIRST.find(t->getType()) != PARAMETERLISTFIRST.end()) {
        if (t->match(TokenType::COMMA)) {
            ++index;
            parameter(tokens, index);
            parameterList(tokens, index);
        }
        else { throw t; }
    }
    else { return; }
}

void Parser::query(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (QUERYFIRST.find(t->getType()) != QUERYFIRST.end()) {
        predicate(tokens, index);
        t = tokens->at(index);
        if (t->match(TokenType::Q_MARK)) {
            ++index;
        }
        else { throw t; }
    }
    else { throw t; }
}

void Parser::queryList(vector<Token*>*& tokens, size_t& index) {
    Token* t = tokens->at(index);
    if (QUERYLISTFIRST.find(t->getType()) != QUERYLISTFIRST.end()) {
        query(tokens, index);
        queryList(tokens, index);
    }
    else { return; }
}