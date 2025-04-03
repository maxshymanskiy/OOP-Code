#include "pch.h"
#include "CppUnitTest.h"
#include "../Money.h"
#include "../Money.cpp"
#include "../Array.h"
#include "../Array.cpp" 



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

        TEST_METHOD(TestConstructorValidSize)
        {
            Money m(5);
            Assert::AreEqual(5, m.getSize());
        }

        TEST_METHOD(TestSetDigitsValid)
        {
            Money m(5);
            m.setDigits("12345");
            Assert::AreEqual(5, (int)m[0]);
        }
        TEST_METHOD(SetDigits_ValidInput_UpdatesArray)
        {
            Money m(5);
            m.setDigits("98765");
            Assert::AreEqual(5, (int)m[0]); // Перевіряємо молодшу цифру
            Assert::AreEqual(6, (int)m[1]);
            Assert::AreEqual(7, (int)m[2]);
            Assert::AreEqual(8, (int)m[3]);
            Assert::AreEqual(9, (int)m[4]); // Перевіряємо старшу цифру
        }

        TEST_METHOD(SetDigits_WithLeadingZeros_Valid)
        {
            Money m(5);
            m.setDigits("00123");
            Assert::AreEqual(3, (int)m[0]);
            Assert::AreEqual(2, (int)m[1]);
            Assert::AreEqual(1, (int)m[2]);
            Assert::AreEqual(0, (int)m[3]);
            Assert::AreEqual(0, (int)m[4]);
        }
	};
}
