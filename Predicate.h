#ifndef PREDICATE_H
#define PREDICATE_H
#include <vector>
#include "Parameter.h"

using std::vector;
class Predicate {
private:
    string id;
    vector<Parameter*> parameters;
public:
    Predicate(string p) : id(p) {}
    ~Predicate() {}
    void addParameter(string);
    string toString();
};

#endif
