#include "pch.h"
#include "CppUnitTest.h"
#include "../Fraction.cpp"
#include "../Fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FractionTests
{
    TEST_CLASS(FractionTests)
    {
    public:
        TEST_METHOD(TestInitValid)
        {
            Fraction frac;
            bool result = frac.Init(10, 5000);
            Assert::IsTrue(result);
            Assert::AreEqual(10L, frac.getWhole());
            Assert::AreEqual((unsigned short)5000, frac.getFractional());
        }

        TEST_METHOD(TestSubtract)
        {
            Fraction frac1 = makeFraction(10, 5000);
            Fraction frac2 = makeFraction(5, 3000);
            Fraction result = frac1.Subtract(frac2);

            Assert::AreEqual(5L, result.getWhole());
            Assert::AreEqual((unsigned short)2000, result.getFractional());
        }

        TEST_METHOD(TestOperatorEqual)
        {
            Fraction frac1 = makeFraction(10, 5000);
            Fraction frac2 = makeFraction(10, 5000);
            Assert::IsTrue(frac1 == frac2);
        }

        TEST_METHOD(TestOperatorNotEqual)
        {
            Fraction frac1 = makeFraction(10, 5000);
            Fraction frac2 = makeFraction(10, 5001);
            Assert::IsFalse(frac1 == frac2);
        }

        TEST_METHOD(TestOperatorLessThan)
        {
            Fraction frac1 = makeFraction(10, 5000);
            Fraction frac2 = makeFraction(10, 5001);
            Assert::IsTrue(frac1 < frac2);
        }

        TEST_METHOD(TestOperatorGreaterThan)
        {
            Fraction frac1 = makeFraction(10, 5001);
            Fraction frac2 = makeFraction(10, 5000);
            Assert::IsTrue(frac1 > frac2);
        }

        TEST_METHOD(TestToString)
        {
            Fraction frac = makeFraction(10, 5000);
            std::string expected = "10.05000";
            Assert::AreEqual(expected, frac.toString()); // Corrected: Two arguments
        }
    };
}