#include "DatalogProgram.h"

void DatalogProgram::createScheme(string id) {
    Predicate* newPredicate = new Predicate(id);
    schemes->push_back(newPredicate);
}

void DatalogProgram::addSchemes(string p) {
}