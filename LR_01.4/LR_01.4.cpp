#include "menu.h"
#include <iostream>


int main() {
    int choice;
    do {
        cout << "\n=== Main Menu ===\n"
            << "1. Circle\n2. Square\n3. Rectangle\n4. Exit\nChoice: ";
        choice = static_cast<int>(readDouble(""));

        switch (choice) {
            case 1: { Circle c; handleShapeMenu(c); break; }
            case 2: { Square s; handleShapeMenu(s); break; }
            case 3: { Rectangle r; handleShapeMenu(r); break; }
        }
    } while (choice != 4);
}