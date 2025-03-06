#include "pch.h"
#include "CppUnitTest.h"
#include "../Square.h"
#include "../Square.cpp"
#include "../utilities.h"
#include "../utilities.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestInit)
        {
            Square square;
            square.Init();

            Assert::AreEqual(0.0, square.getX());
            Assert::AreEqual(0.0, square.getY());
            Assert::AreEqual(1.0, square.getSide());
            Assert::AreEqual(0.0, square.getAngle());
        }

        TEST_METHOD(TestSetSide)
        {
            Square square;
            square.setSide(-5.0); // Негативне значення
            Assert::AreEqual(1.0, square.getSide()); // Має бути 1.0

            square.setSide(10.0);
            Assert::AreEqual(10.0, square.getSide());
        }

        TEST_METHOD(TestMove)
        {
            Square square;
            square.Init();
            square.move(2.0, -3.0);

            Assert::AreEqual(2.0, square.getX());
            Assert::AreEqual(-3.0, square.getY());
        }

        TEST_METHOD(TestResize)
        {
            Square square;
            square.Init();
            square.resize(5.0);

            Assert::AreEqual(5.0, square.getSide());
        }
        
        TEST_METHOD(TestRotate)
        {
            Square square;
            square.Init();
            square.rotate(45.0);

            Assert::AreEqual(45.0, square.getAngle());

            square.rotate(400.0); // Обертання на 400 градусів
            Assert::AreEqual(85.0, square.getAngle()); // 45 + 400 = 445 → 445 % 360 = 85
        }

        TEST_METHOD(TestToString)
        {
            Square square;
            square.Init();
            square.move(2.0, 3.0);
            square.resize(4.0);
            square.rotate(90.0);

            std::string expected = "Square [x=2, y=3, side=4, angle=90°]";
            Assert::AreEqual(expected, square.toString());
        }
	};
}
