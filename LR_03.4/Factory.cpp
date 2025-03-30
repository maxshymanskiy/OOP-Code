#include "Factory.h"
#include <algorithm>
#include <iostream>


SymString* Factory::createSymString(const std::string& id, const std::string& value) {
    SymString* obj = new SymString(id, value);
    objects.push_back(obj);
    return obj;
}

HexString* Factory::createHexString(const std::string& id, const std::string& value) {
    HexString* obj = new HexString(id, value);
    objects.push_back(obj);
    return obj;
}

bool Factory::deleteObject(const std::string& id) {
    auto it = std::find_if(objects.begin(), objects.end(),
        [&id](SymString* obj) { return obj->getId() == id; });
    if (it != objects.end()) {
        delete* it;
        objects.erase(it);
        return true;
    }
    return false;
}

void Factory::showAllObjects() const {
    if (objects.empty()) {
        std::cout << "\nСписок об'єктів порожній.\n";
        return;
    }
    for (const auto& obj : objects) {
        std::cout << "ID: " << obj->getId()
            << "\nЗначення: " << obj->getValue()
            << "\nБінарний вигляд: " << obj->showBin()
            << "\n\n";
    }
}

SymString* Factory::findObject(const std::string& id) const {
    auto it = std::find_if(objects.begin(), objects.end(),
        [&id](SymString* obj) { return obj->getId() == id; });
    return (it != objects.end()) ? *it : nullptr;
}

Factory::~Factory() {
    for (auto obj : objects) {
        delete obj;
    }
}