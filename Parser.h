#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <set>
#include "Token.h"
#include "Lexer.h"
#include "DatalogProgram.h"

using std::set;
using std::vector;
class Parser {
private:
    vector<Token*>* tokens;
    set<TokenType> DATALOGFIRST { TokenType::SCHEMES };
    set<TokenType> DATALOGFOLLOW { TokenType::UNDEFINED };
    set<TokenType> SCHEMELISTFIRST { TokenType::ID };
    set<TokenType> SCHEMELISTFOLLOW { TokenType::FACTS };
    set<TokenType> FACTLISTFIRST { TokenType::ID };
    set<TokenType> FACTLISTFOLLOW { TokenType::RULES};
    set<TokenType> RULELISTFIRST { TokenType::ID };
    set<TokenType> RULELISTFOLLOW { TokenType::QUERIES };
    set<TokenType> QUERYLISTFIRST { TokenType::ID };
    set<TokenType> QUERYLISTFOLLOW { TokenType::END };
    set<TokenType> SCHEMEFIRST { TokenType::ID };
    set<TokenType> SCHEMEFOLLOW { TokenType::ID };
    set<TokenType> FACTFIRST { TokenType::ID };
    set<TokenType> FACTFOLLOW { TokenType::ID };
    set<TokenType> RULEFIRST { TokenType::ID };
    set<TokenType> RULEFOLLOW { TokenType::ID };
    set<TokenType> QUERYFIRST { TokenType::ID };
    set<TokenType> QUERYFOLLOW { TokenType::ID };
    set<TokenType> HEADPREDICATEFIRST { TokenType::ID };
    set<TokenType> HEADPREDICATEFOLLOW { TokenType::COLON_DASH };
    set<TokenType> PREDICATEFIRST { TokenType::ID };
    set<TokenType> PREDICATEFOLLOW { TokenType::COMMA, TokenType::Q_MARK };
    set<TokenType> PREDICATELISTFIRST { TokenType::COMMA };
    set<TokenType> PREDICATELISTFOLLOW { TokenType::PERIOD };
    set<TokenType> PARAMETERLISTFIRST { TokenType::COMMA };
    set<TokenType> PARAMETERLISTFOLLOW { TokenType::RIGHT_PAREN };
    set<TokenType> STRINGLISTFIRST { TokenType::COMMA };
    set<TokenType> IDLISTFIRST { TokenType::COMMA };
    set<TokenType> PARAMETERFIRST { TokenType::STRING, TokenType::ID };
    set<TokenType> PARAMETERFOLLOW { TokenType::COMMA };


    void datalog(vector<Token*>*&);
    void scheme(vector<Token*>*&, size_t&);
    void schemeList(vector<Token*>*&, size_t&);
    void idList(vector<Token*>*&, size_t&);
    void fact(vector<Token*>*&, size_t&);
    void factList(vector<Token*>*&, size_t&);
    void stringList(vector<Token*>*&, size_t&);
    void rule(vector<Token*>*&, size_t&);
    void ruleList(vector<Token*>*&, size_t&);
    void headPredicate(vector<Token*>*&, size_t&);
    void predicate(vector<Token*>*&, size_t&);
    void predicateList(vector<Token*>*&, size_t&);
    void parameter(vector<Token*>*&, size_t&);
    void parameterList(vector<Token*>*&, size_t&);
    void query(vector<Token*>*&, size_t&);
    void queryList(vector<Token*>*&, size_t&);


public:
    Parser(vector<Token*>* t) : tokens(t) {}
    ~Parser() = default;
    void Parse();
};

#endif
