#include "pch.h"
#include "CppUnitTest.h"
#include "../Combination.h"
#include "../LR_01.1.cpp"
#include "../Combination.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

        TEST_METHOD(TestInit_InvalidInput_kGreaterThanN)
        {
            Combination c;
            bool result = c.Init(5, 3);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestInit_InvalidInput_NegativeNumbers)
        {
            Combination c;
            bool result = c.Init(-2, 10);
            Assert::IsFalse(result);
        }
        TEST_METHOD(TestCombination_ValidInput)
        {
            Combination c;
            c.Init(3, 5);
            unsigned long long result = c.combination();
            Assert::AreEqual(10ULL, result);
        }

        TEST_METHOD(TestCombination_AnotherValidInput)
        {
            Combination c;
            c.Init(2, 10);
            unsigned long long result = c.combination();
            Assert::AreEqual(45ULL, result);
        }
	};
}
