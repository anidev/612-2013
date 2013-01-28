#include <vector>
#include "UpdateRegistry.h"

UpdateRegistry::UpdateRegistry() {
    std::printf("Registry Created");
}
UpdateRegistry::~UpdateRegistry() {
}
void UpdateRegistry::addUpdateFunction(functionName f,inst i) {
    instances.push_back(i);
    functions.push_back(f);
    std::printf("Function added!\n");
}
void UpdateRegistry::updateAll() {
    std::printf("Size: %i \n", instances.size());
    for(unsigned int x = 0; x < instances.size(); x++)
    {
        (functions.at(x))(instances.at(x));
        std::printf("function called\n");
    }
}
