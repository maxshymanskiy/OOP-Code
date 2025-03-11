#pragma once
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "utilities.h"
using namespace std;

template<typename T>
void handleShapeMenu(T& shape) {
    int choice;
    do {
        cout << "\n=== Menu ===\n"
            << "1. Init\n2. Read\n3. Display\n"
            << "4. Move\n5. Resize\n6. Rotate\n7. Back\nChoice: ";
        choice = static_cast<int>(readDouble(""));
        switch (choice) {
        case 1:
            shape.Init();  // Remove the if condition since Init() returns void
            break;
        case 2:
            shape.Read();
            break;
        case 3:
            shape.Display();
            break;
        case 4: {
            double dx = readDouble("Enter dx: ");
            double dy = readDouble("Enter dy: ");
            shape.move(dx, dy);
            break;
        }
        case 5:
            if (!shape.promptAndResize())
                cout << "Resize operation failed. Value was invalid.\n";
            break;
        case 6: {
            double angle = readDouble("Enter angle: ");
            shape.rotate(angle);  // Remove the if condition since rotate() returns void
            break;
        }
        case 7:
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}