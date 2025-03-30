#pragma once
#include "SymString.h"
#include "HexString.h"
#include <vector>
#include <Windows.h>

class Factory {
private:
    std::vector<SymString*> objects;

public:
    SymString* createSymString(const std::string& id, const std::string& value);
    HexString* createHexString(const std::string& id, const std::string& value);
    bool deleteObject(const std::string& id);
    void showAllObjects() const;
    SymString* findObject(const std::string& id) const;
    ~Factory();
};