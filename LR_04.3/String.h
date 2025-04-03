#pragma once
#include "Array.h"

class String : public Array {
public:
    String(int maxLength = 255);
    String(const char* str, int maxLength = 255);
    void setContent(const char* str);
    int length() const;
    int find(const char* substr) const;
    void remove(int start, int len);
    void insert(int pos, const char* substr);
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const String& s);
    friend std::istream& operator>>(std::istream& is, String& s);

    virtual String* add(const Array& other) const override;
};