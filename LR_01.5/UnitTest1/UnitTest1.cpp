#include "pch.h"
#include "CppUnitTest.h"
#include "../Triad.h"
#include "../Triad.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestSetValues)
        {
            Triad t;
            t.Init(1, 2, 3);

            Assert::AreEqual(1, t.getX());
            Assert::AreEqual(2, t.getY());
            Assert::AreEqual(3, t.getZ());
        }

        TEST_METHOD(TestAddNumber)
        {
            Triad t;
            t.Init(1, 2, 3);
            t.addNumber(5);

            Assert::AreEqual(6, t.getX());
            Assert::AreEqual(7, t.getY());
            Assert::AreEqual(8, t.getZ());
        }

        TEST_METHOD(TestMultiplyByNumber)
        {
            Triad t;
            t.Init(1, 2, 3);
            t.multiplyByNumber(2);

            Assert::AreEqual(2, t.getX());
            Assert::AreEqual(4, t.getY());
            Assert::AreEqual(6, t.getZ());
        }

        TEST_METHOD(TestIsEqual)
        {
            Triad t1;
            t1.Init(1, 2, 3);

            Triad t2;
            t2.Init(1, 2, 3);

            Assert::IsTrue(t1.isEqual(t2));
        }
	};
}
