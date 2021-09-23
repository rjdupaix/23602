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

//inline Lexer::Lexer() {}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
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

    // TODO: Add the other needed automata here
}


void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    //set lineNumber to 1
    int lineNumber = 1;
    int maxRead;
    // While there are more characters to tokenize
    //loop while input.size() > 0 {
    while (input.size() > 0) {
        //set maxRead to 0
        maxRead = 0;
        //set maxAutomaton to the first automaton in automata
        Automaton* maxAutomaton = automata->at(0);
        // TODO: you need to handle whitespace inbetween tokens
        while (!(input.empty()) && isspace(input[maxRead])) {
            if (input[maxRead] == '\n'/* && input.size() > 1*/) {
                lineNumber++;
            }
            input = input.substr(maxRead + 1);
        }
        if (input.empty()) {
            break;
        }

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        //foreach automaton in automata {
        for (int i = 0; i < automata->size(); ++i){
            //inputRead = automaton->at.Start(input)
            int inputRead = 0;
            inputRead = automata->at(i)->Start(input);
            //if (inputRead > maxRead) {
            if (inputRead > maxRead) {
                //set maxRead to inputRead
                maxRead = inputRead;
                //set maxAutomaton to automaton
                maxAutomaton = automata->at(i);
            }
        }
        // Here is the "Max" part of the algorithm
        //if maxRead > 0 {
        if (maxRead > 0) {
            //set newToken to maxAutomaton.CreateToken(...)
            //maxAutomaton->CreateToken(input, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);//->CreateToken(input, lineNumber);
            lineNumber += maxAutomaton->NewLinesInToken();
            //increment lineNumber by maxAutomaton.NewLinesRead()
                //add newToken to collection of all tokens
            tokens->push_back(newToken);
            //cout << maxRead << " " << lineNumber << std::endl;
        }
        // No automaton accepted input
        // Create single character undefined token
        //else {
        else {
            //set maxRead to 1
            maxRead = 1;
                //set newToken to a  new undefined Token
            Token* newToken = new Token(TokenType::UNDEFINED, input.substr(0, maxRead), lineNumber);

//                //(with first character of input)
//                //add newToken to collection of all tokens
            tokens->push_back(newToken);
        }
        // Update `input` by removing characters read to create Token
        //remove maxRead characters from input
        input.erase(0, maxRead);
    //}
    //add end of file token to all tokens
    }
    Token* end = new Token(TokenType::END, "", lineNumber);
    tokens->push_back(end);
    for (int j = 0; j < tokens->size(); ++j) {
        tokens->at(j)->toString();
    }
    cout << "Total Tokens = " << tokens->size();
}
