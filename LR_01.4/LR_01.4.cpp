#include <iostream>
#include <vector>
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
using namespace std;

void showMenu() {
    cout << "\n=== Main Menu ===\n"
        << "1. Circle\n"
        << "2. Square\n"
        << "3. Rectangle\n"
        << "4. Demo Arrays\n"
        << "0. Exit\n"
        << "Choice: ";
}

void handleCircle() {
    Circle c;
    int choice;
    do {
        cout << "\n=== Circle Menu ===\n"
            << "1. Init\n2. Read\n3. Display\n4. Move\n5. Resize (radius)\n6. Rotate\n7. toString\n8. Back\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: c.Init(); break;
        case 2: c.Read(); break;
        case 3: c.Display(); break;
        case 4: {
            double dx, dy;
            cout << "Enter dx dy: "; cin >> dx >> dy;
            c.move(dx, dy);
            break;
        }
        case 5: {
            double r;
            cout << "New radius: "; cin >> r;
            c.resize(r);
            break;
        }
        case 6: {
            double a;
            cout << "Angle: "; cin >> a;
            c.rotate(a);
            break;
        }
        case 7: cout << c.toString() << endl; break;
        }
    } while (choice != 8);
}

void handleSquare() {
    Square s;
    int choice;
    do {
        cout << "\n=== Square Menu ===\n"
            << "1. Init\n2. Read\n3. Display\n4. Move\n5. Resize\n6. Rotate\n7. toString\n8. Back\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: s.Init(); break;
        case 2: s.Read(); break;
        case 3: s.Display(); break;
        case 4: {
            double dx, dy;
            cout << "Enter dx dy: "; cin >> dx >> dy;
            s.move(dx, dy);
            break;
        }
        case 5: {
            double side;
            cout << "New side: "; cin >> side;
            s.resize(side);
            break;
        }
        case 6: {
            double a;
            cout << "Angle: "; cin >> a;
            s.rotate(a);
            break;
        }
        case 7: cout << s.toString() << endl; break;
        }
    } while (choice != 8);
}

void handleRectangle() {
    Rectangle r;
    int choice;
    do {
        cout << "\n=== Rectangle Menu ===\n"
            << "1. Init\n2. Read\n3. Display\n4. Move\n5. Resize\n6. Rotate\n7. toString\n8. Back\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: r.Init(); break;
        case 2: r.Read(); break;
        case 3: r.Display(); break;
        case 4: {
            double dx, dy;
            cout << "Enter dx dy: "; cin >> dx >> dy;
            r.move(dx, dy);
            break;
        }
        case 5: {
            double w, h;
            cout << "New width height: "; cin >> w >> h;
            r.resize(w, h);
            break;
        }
        case 6: {
            double a;
            cout << "Angle: "; cin >> a;
            r.rotate(a);
            break;
        }
        case 7: cout << r.toString() << endl; break;
        }
    } while (choice != 8);
}

void demoArrays() {
    Circle circles[2];
    circles[0].Init();
    circles[1].Read();

    Square squares[2];
    squares[0].Init();
    squares[1].Read();

    Rectangle rects[2];
    rects[0].Init();
    rects[1].Read();

    cout << "\nCircles Array:\n";
    for (auto& c : circles) c.Display();

    cout << "\nSquares Array:\n";
    for (auto& s : squares) s.Display();

    cout << "\nRectangles Array:\n";
    for (auto& r : rects) r.Display();
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
        case 1: handleCircle(); break;
        case 2: handleSquare(); break;
        case 3: handleRectangle(); break;
        case 4: demoArrays(); break;
        }
    } while (choice != 0);
    return 0;
}