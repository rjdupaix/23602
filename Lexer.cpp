#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "AddAutomaton.h"
#include "Facts.h"
#include "ID.h"
#include "Left_Paren.h"
#include "Multiply.h"
#include "Period.h"
#include "Q_Mark.h"
#include "Queries.h"
#include "Right_Paren.h"
#include "Rules.h"
#include "Schemes.h"
#include "String.h"
#include "Single_Comment.h"
#include "Multi_Comment.h"

Lexer::~Lexer() {
    delete automata;
    delete tokens;
}

void Lexer::CreateAutomata() {
    automata->push_back(new ColonAutomaton());
    automata->push_back(new ColonDashAutomaton());
    automata->push_back(new CommaAutomaton());
    automata->push_back(new AddAutomaton());
    automata->push_back(new Facts());
    automata->push_back(new String());
    automata->push_back(new Left_ParenAutomaton());
    automata->push_back(new MultiplyAutomaton());
    automata->push_back(new PeriodAutomaton());
    automata->push_back(new Q_MarkAutomaton());
    automata->push_back(new Queries());
    automata->push_back(new Right_ParenAutomaton());
    automata->push_back(new Rules());
    automata->push_back(new Schemes());
    automata->push_back(new Single_Comment());
    automata->push_back(new Multi_Comment());
    automata->push_back(new ID());
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    int maxRead = 0;

    while (input.size() > 0) {
        maxRead = 0;
        Automaton* maxAutomaton = automata->at(0);
        while (!(input.empty()) && isspace(input.front())) {
            if (input[maxRead] == '\n') {
                lineNumber++;
            }
            input = input.substr(maxRead + 1);
        }
        if (input.empty()) {
            break;
        }
        for (long unsigned int i = 0; i < (automata->size()); ++i){
            int inputRead = 0;
            inputRead = automata->at(i)->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata->at(i);
            }
        }
        if (maxRead > 0) {
            lineNumber += maxAutomaton->NewLinesRead();
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesInToken();
            tokens->push_back(newToken);
        }
        else {
            maxRead = 1;
            Token* newToken = new Token(TokenType::UNDEFINED, input.substr(0, maxRead), lineNumber);
            tokens->push_back(newToken);
        }
        input.erase(0, maxRead);
    }
    Token* end = new Token(TokenType::END, "", lineNumber);
    tokens->push_back(end);
    for (long unsigned int j = 0; j < tokens->size(); ++j) {
        tokens->at(j)->toString();
    }
    cout << "Total Tokens = " << tokens->size();

}

std::vector<Token*>* Lexer::ReturnTokens() {
    return tokens;
}