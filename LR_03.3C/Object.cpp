#include "Object.h"

int Object::counter = 0;

Object::Object() {
    counter++;
}

Object::~Object() {
    counter--;
}