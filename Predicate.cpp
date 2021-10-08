#include "Predicate.h"

string Predicate::toString() {
    for (int i = 0; i < parameters.size(); ++i) {
        parameters.at(i)->toString();
    }
}

void Predicate::addParameter(string p) {
    parameters.push_back(new Parameter(p));
}