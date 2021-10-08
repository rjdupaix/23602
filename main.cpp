#include "Lexer.h"
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Please provide name of input file";
        return 1;
    }
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    char c = '\0';
    string line = "";

    while (true) {
        in.get(c);
        if (c == '\0') { break; }
        line += c;
        //line.push_back(c);
        if (in.peek() == EOF) { break; }
    }

    Lexer* lexer = new Lexer();

    lexer->Run(line);

    Parser t(lexer->ReturnTokens());
    try {
        t.Parse();
        cout << endl << "Success!" << endl;
    }
    catch (Token* error) {
        cout << endl << "Failure!  " << endl;
        error->toString();
    }



    delete lexer;

    return 0;
}