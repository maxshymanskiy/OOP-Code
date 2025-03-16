#include "pch.h"
#include "CppUnitTest.h"
#include "../Fraction.h"
#include "../Fraction.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestDefaultConstructor)
        {
            Fraction f;
            Assert::AreEqual(0L, f.getWhole());
            Assert::AreEqual((unsigned short)0, f.getFractional());
        }

        TEST_METHOD(TestParameterizedConstructor)
        {
            Fraction f(123, 45678);
            Assert::AreEqual(123L, f.getWhole());
            Assert::AreEqual((unsigned short)45678, f.getFractional());
        }

        TEST_METHOD(TestCopyConstructor)
        {
            Fraction original(123, 45678);
            Fraction copy = original;
            Assert::AreEqual(original.getWhole(), copy.getWhole());
            Assert::AreEqual(original.getFractional(), copy.getFractional());
        }

        // Тести методів доступу
        TEST_METHOD(TestSettersAndGetters)
        {
            Fraction f;
            Assert::IsTrue(f.setWhole(42));
            Assert::IsTrue(f.setFractional(12345));
            Assert::AreEqual(42L, f.getWhole());
            Assert::AreEqual((unsigned short)12345, f.getFractional());
        }

        // Тести перевантажених операторів порівняння
        TEST_METHOD(TestEqualityOperators)
        {
            Fraction f1(10, 20000);
            Fraction f2(10, 20000);
            Fraction f3(10, 30000);

            Assert::IsTrue(f1 == f2);
            Assert::IsFalse(f1 == f3);
            Assert::IsTrue(f1 != f3);
            Assert::IsFalse(f1 != f2);
        }
	};
}
