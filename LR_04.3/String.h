#pragma once
#include "Array.h"
#include <string>

class String : public Array {
private:
    void validatePosition(int pos, bool allowEnd = false) const;
    void validateSubstring(const char* substr) const;
public:
    String(int maxLength = 255);
    String(const char* str, int maxLength = 255);

    int length() const;
    int find(const char* substr) const;
    void remove(int start, int len);
    void insert(int pos, const char* substr);
    std::string toString() const;

    void setContent(const char* str);
    void setChar(int index, char c);
    void setMaxLength(int newMaxLength);

    friend std::ostream& operator<<(std::ostream& os, const String& s);
    friend std::istream& operator>>(std::istream& is, String& s);

    virtual String* add(const Array& other) const override;


};
