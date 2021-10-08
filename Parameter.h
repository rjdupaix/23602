#ifndef PARAMETER_H
#define PARAMETER_H
#include <string>

using std::string;
class Parameter
        {
private:
    string p;
public:
    Parameter(string param) : p(param) {}
    ~Parameter() {}
    string toString();
};

#endif
