#include "Lexer.h"
#include <fstream>
#include <iostream>
#include <string>

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
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }

    string line;
    char c;
    while (true) {
        in.get(c);
        line.push_back(c);
        if (in.peek() == EOF) { break; }
    }

    Lexer* lexer = new Lexer();

    //cout << line << endl;
    // TODO
    lexer->Run(line);

    //delete lexer;

    return 0;
}