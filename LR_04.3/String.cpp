#include "String.h"
#include <cstring>


String::String(const char* str, int maxLength) : Array(maxLength + 1, 0) {
    setContent(str);
}
String::String(int maxLength) : Array(maxLength + 1, 0) {
	array[0] = 0; // ���������� ������� �����
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
    validateSubstring(str); // �������� �� nullptr

    int len = strlen(str);
    if (len > getSize() - 1) len = getSize() - 1;

    array[0] = len;
    for (int i = 0; i < len; ++i) {
        array[i + 1] = str[i];
    }
}

void String::setChar(int index, char c) {
    validatePosition(index); // �������� 0 <= index < length()
    array[index + 1] = c;
}

void String::setMaxLength(int newMaxLength) {
    if (newMaxLength < 1 || newMaxLength > 255) {
        std::cerr << "Error: Invalid max length" << std::endl;
        exit(1);
    }

    unsigned char* newArray = new unsigned char[newMaxLength + 1] {};
    int copyLength = std::min(length(), newMaxLength);

    newArray[0] = copyLength;
    for (int i = 0; i < copyLength; ++i) {
        newArray[i + 1] = array[i + 1];
    }

    delete[] array;
    array = newArray;
    size = newMaxLength + 1;
}

std::string String::toString() const {
    return std::string((char*)(array + 1), length());
}

int String::length() const { return array[0]; }

int String::find(const char* substr) const {
    int subLen = strlen(substr);
    if (subLen == 0 || subLen > length()) return -1;

    for (int i = 1; i <= length() - subLen + 1; ++i) {
        bool found = true;
        for (int j = 0; j < subLen; ++j) {
            if (array[i + j] != substr[j]) {
                found = false;
                break;
            }
        }
        if (found) return i - 1; // ��������� ������ � �������� ������
    }
    return -1;
}

void String::remove(int start, int len) {
    if (start < 0 || len < 0 || start + len > length()) {
        std::cerr << "�������: ����� ��������� ���������" << std::endl;
        exit(1);
    }

    for (int i = start + 1; i <= length() - len; ++i) {
        array[i] = array[i + len];
    }
    array[0] -= len;
}

void String::insert(int pos, const char* substr) {
    int subLen = strlen(substr);
    if (pos < 0 || pos > length() || length() + subLen > getSize() - 1) {
        std::cerr << "�������: ������ ������� �������" << std::endl;
        exit(1);
    }

    // ���� ������
    for (int i = length(); i >= pos; --i) {
        array[i + subLen + 1] = array[i + 1];
    }
    // ������� �������
    for (int i = 0; i < subLen; ++i) {
        array[pos + i + 1] = substr[i];
    }
    array[0] += subLen;
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

String* String::add(const Array& other) const {
    const String* s = dynamic_cast<const String*>(&other);
    if (!s) {
        std::cerr << "�������: ������� ���" << std::endl;
        exit(1);
    }

    int newLength = length() + s->length();
    String* result = new String(newLength + 1); // +1 ��� ������� �������

    for (int i = 1; i <= length(); ++i) {
        result->array[i] = array[i];    // ������� ������� � ��������� �����
    }
    for (int i = 1; i <= s->length(); ++i) {
        result->array[length() + i] = s->array[i];  // ������� ������� � ������� �����
    }

    // ������������ ������� ������������� �����
    result->array[0] = newLength;

    return result;
}