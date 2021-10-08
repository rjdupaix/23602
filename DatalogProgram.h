#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H
#include "Predicate.h"

using std::vector;
class DatalogProgram {
private:
    vector<Predicate*>* facts;
    vector<Predicate*>* schemes;
    //vector<Token*>* rules;
    vector<Predicate*>* queries;
public:
    DatalogProgram() {  }
    void createScheme(string);
    void addSchemes(string);
};

#endif
