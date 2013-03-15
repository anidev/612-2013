#include <vector>
#include "updateRegistry.h"

UpdateRegistry::UpdateRegistry() {
}

UpdateRegistry::~UpdateRegistry() {
}

void UpdateRegistry::addUpdateFunction(functionName f,inst i) {
    instances.push_back(i);
    functions.push_back(f);
}

void UpdateRegistry::updateAll() {
    for(unsigned int x = 0; x < instances.size(); x++)
    {
        (functions.at(x))(instances.at(x));
    }
}
