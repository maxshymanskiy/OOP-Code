#pragma once
class Object {
private:
    static int counter;
public:
    Object();
    virtual ~Object();
    static int getCounter() { return counter; }
};