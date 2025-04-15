#include "String.h"
#include <cstring>

String::String(const char* str, int maxLength) : Array(std::min(maxLength, MAX_STRING_SIZE - 1) + 1, 0) {
    setContent(str);
}

String::String(int maxLength) : Array(std::min(maxLength, MAX_STRING_SIZE - 1) + 1, 0) {
    array[0] = 0; 
}

void String::validatePosition(int pos, bool allowEnd) const {
    int upperBound = allowEnd ? length() : length() - 1;
    if (pos < 0 || pos > upperBound) {
        std::cerr << "Error: Invalid position " << pos << std::endl;
        exit(1);
    }
}

void String::validateSubstring(const char* substr) const {
    if (!substr) {
        std::cerr << "Error: Null substring" << std::endl;
        exit(1);
    }
}

void String::setContent(const char* str) {
    validateSubstring(str);

    int len = strlen(str);
    if (len > getSize() - 1) len = getSize() - 1;

    array[0] = len;
    memcpy(array + 1, str, len);
}

void String::setChar(int index, char c) {
    validatePosition(index);
    array[index + 1] = c;
}

void String::setMaxLength(int newMaxLength) {
    if (newMaxLength < 1 || newMaxLength > MAX_STRING_SIZE - 1) {
        std::cerr << "Error: Invalid max length. Must be between 1 and " << (MAX_STRING_SIZE - 1) << std::endl;
        exit(1);
    }

    unsigned char* newArray = new unsigned char[newMaxLength + 1] {};
    int copyLength = std::min(length(), newMaxLength);

    newArray[0] = copyLength;
    memcpy(newArray + 1, array + 1, copyLength);

    delete[] array;
    array = newArray;
    size = newMaxLength + 1;
}

std::string String::toString() const {
    return std::string((char*)(array + 1), length());
}

int String::length() const {
    return array[0];
}

int String::find(const char* substr) const {
    validateSubstring(substr);

    int subLen = strlen(substr);
    if (subLen == 0 || subLen > length()) return -1;

    for (int i = 0; i <= length() - subLen; ++i) {
        if (memcmp(array + 1 + i, substr, subLen) == 0) {
            return i;
        }
    }
    return -1;
}

String* String::substring(int start, int len) const {
    validatePosition(start, true);

    if (len < 0 || start + len > length()) {
        std::cerr << "Error: Invalid substring parameters" << std::endl;
        exit(1);
    }

    String* result = new String(len + 1);
    memcpy(result->array + 1, array + start + 1, len);
    result->array[0] = len;

    return result;
}

void String::remove(int start, int len) {
    validatePosition(start, true);

    if (len < 0 || start + len > length()) {
        std::cerr << "Error: Invalid removal parameters" << std::endl;
        exit(1);
    }

    if (start + len < length()) {
        memmove(array + start + 1, array + start + len + 1, length() - start - len);
    }
    array[0] -= len; // 6 + 5 = 11. Зменшити довжину рядка в першому байті
}

void String::removeSubstring(const char* substr) {
    validateSubstring(substr);

    int position = find(substr);
    if (position != -1) {
        remove(position, strlen(substr));
    }
}

void String::insert(int pos, const char* substr) {
    validatePosition(pos, true);
    validateSubstring(substr);

    int substrLength = strlen(substr);

    if (length() + substrLength > getSize() - 1) {
        std::cerr << "Error: Not enough space for insertion" << std::endl;
        exit(1);
    }

    if (pos < length()) {
        memmove(array + pos + substrLength + 1, array + pos + 1, length() - pos);
    }
    memcpy(array + pos + 1, substr, substrLength);

    array[0] += substrLength;
}

String* String::add(const Array& other) const {
    const String* s = dynamic_cast<const String*>(&other);
    if (!s) {
        std::cerr << "Error: Invalid type" << std::endl;
        exit(1);
    }

    int newLength = length() + s->length();
    if (newLength > MAX_STRING_SIZE - 1) {
        newLength = MAX_STRING_SIZE - 1;
        std::cerr << "Warning: String concatenation truncated to maximum length of " << (MAX_STRING_SIZE - 1) << std::endl;
    }

    String* result = new String(newLength);

    memcpy(result->array + 1, array + 1, length());

    int secondLength = std::min(s->length(), MAX_STRING_SIZE - 1 - length());
    memcpy(result->array + length() + 1, s->array + 1, secondLength);

    result->array[0] = length() + secondLength;
    return result;
}

std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.toString();
    return os;
}

std::istream& operator>>(std::istream& is, String& s) {
    std::string input;
    is >> input;
    s.setContent(input.c_str());
    return is;
}