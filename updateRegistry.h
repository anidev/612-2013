#ifndef UPDATE_REGISTRY_H
#define UPDATE_REGISTRY_H
#include <vector>
class UpdateRegistry {
public:
    typedef void* inst;
    typedef void(*functionName)(inst);
    UpdateRegistry();
    ~UpdateRegistry();
    void updateAll();
    void addUpdateFunction(functionName,inst);
private:
    std::vector<inst> instances;
    std::vector<functionName> functions;
};
#endif
