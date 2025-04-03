#include "Money.h"
#include <sstream>
#include <cstring>
#include <cctype>

Money::Money(int size, unsigned char initVal) : Array(size, initVal) {
    if (size < 2 || size > 100) {
        std::cerr << "Error: Money size must be 2-100" << std::endl;
        exit(1);
    }
}

void Money::setDigits(const std::string& digits) {
    if (digits.length() > 100) {
        std::cerr << "Error: Maximum 100 digits allowed" << std::endl;
        exit(1);
    }
    // Оновлюємо розмір масиву
    delete[] array;
    size = digits.length();
    array = new unsigned char[size];

    // Заповнюємо масив у зворотному порядку
    for (int i = 0; i < size; ++i) {
        char c = digits[size - 1 - i];
        if (!isdigit(c)) {
            std::cerr << "Error: Non-digit character found" << std::endl;
            exit(1);
        }
        array[i] = c - '0';
    }
}

std::string Money::toString() const {
    std::stringstream ss;

    // Виводимо гривні (всі цифри крім останніх двох)
    for (int i = size - 1; i >= 2; --i) {
        ss << (int)array[i];
    }

    // Додаємо роздільник, якщо є гривні
    if (size > 2) ss << " грн ";

    // Виводимо копійки (останні дві цифри)
    ss << (int)array[1] << (int)array[0] << " коп";

    return ss.str();
}

Money* Money::add(const Array& other) const {
    const Money* m = dynamic_cast<const Money*>(&other);
    if (!m) {
        std::cerr << "Error: Invalid money type" << std::endl;
        exit(1);
    }

    int maxSize = (size > m->size) ? size : m->size;
    Money* result = new Money(maxSize + 1);  // +1 для можливого переносу

    int carry = 0;
    for (int i = 0; i < maxSize + 1; ++i) {
        int digit1 = (i < size) ? array[i] : 0;
        int digit2 = (i < m->size) ? m->array[i] : 0;
        int sum = digit1 + digit2 + carry;

        result->array[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        // Якщо залишився перенос після всіх розрядів
        delete result;
        std::cerr << "Error: Дуже велике переповнення" << std::endl;
        exit(1);
    }

    // Видаляємо ведучі нулі, якщо вони є
    while (result->size > 2 && result->array[result->size - 1] == 0) {
        result->size--;
    }

    return result;
}
std::ostream& operator<<(std::ostream& os, const Money& m) {
    os << m.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Money& m) {
    std::string input;
    is >> input;

    // Видаляємо всі нецифрові символи
    input.erase(std::remove_if(input.begin(), input.end(),
        [](char c) { return !isdigit(c); }), input.end());

    if (input.empty()) {
        std::cerr << "Error: No digits found" << std::endl;
        exit(1);
    }

    // Додаємо ведучі нулі, якщо цифр менше 2
    if (input.length() < 2) {
        input = std::string(2 - input.length(), '0') + input;
    }

    m.setDigits(input);
    return is;
}