#pragma once

class Object {
protected:
    static int count; // Статичний лічильник об'єктів

public:
    Object(); // Конструктор за замовчуванням
    Object(const Object&); // Конструктор копіювання
    ~Object(); // Деструктор

    static int getCount(); // Метод для отримання лічильника
};