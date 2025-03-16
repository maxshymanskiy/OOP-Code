#include "pch.h"
#include "CppUnitTest.h"
#include "../Combination.cpp"
#include "../Combination.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestDefaultConstructor)
        {
            Combination c;
            Assert::AreEqual(0, c.GetFirst());
            Assert::AreEqual(0, c.GetSecond());
        }

        TEST_METHOD(TestParameterizedConstructor)
        {
            Combination c(2, 5);
            Assert::AreEqual(2, c.GetFirst());
            Assert::AreEqual(5, c.GetSecond());

            Combination invalid(5, 2);
            Assert::AreEqual(0, invalid.GetFirst());
            Assert::AreEqual(0, invalid.GetSecond());
        }

        TEST_METHOD(TestPrefixIncrement)
        {
            Combination c(2, 5);
            ++c;
            Assert::AreEqual(3, c.GetFirst());
        }

        TEST_METHOD(TestPostfixIncrement)
        {
            Combination c(2, 5);
            Combination temp = c++;
            Assert::AreEqual(2, temp.GetFirst());
            Assert::AreEqual(6, c.GetSecond());
        }
	};
}
