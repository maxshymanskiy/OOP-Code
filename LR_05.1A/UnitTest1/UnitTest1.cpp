#include "pch.h"
#include "CppUnitTest.h"
#include "../Combination.h"
#include "../Combination.cpp"


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

		TEST_METHOD(TestParameterizedConstructor_Valid)
		{
			Combination c(3, 5);
			Assert::AreEqual(3, c.GetFirst());
			Assert::AreEqual(5, c.GetSecond());
		}

		TEST_METHOD(TestParameterizedConstructor_InvalidK)
		{
			auto func = []() { Combination c(-1, 5); };
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(TestParameterizedConstructor_InvalidN)
		{
			auto func = []() { Combination c(3, -1); };
			Assert::ExpectException<InvalidSecondException>(func);
		}

		TEST_METHOD(TestParameterizedConstructor_KGreaterThanOrEqualN)
		{
			auto func = []() { Combination c(5, 5); };
			Assert::ExpectException<CombinationCustomException>(func);
		}

		TEST_METHOD(TestCopyConstructor)
		{
			Combination c1(3, 5);
			Combination c2(c1);
			Assert::AreEqual(3, c2.GetFirst());
			Assert::AreEqual(5, c2.GetSecond());
		}

		TEST_METHOD(TestSetFirst_Valid)
		{
			Combination c(3, 5);
			c.SetFirst(2);
			Assert::AreEqual(2, c.GetFirst());
		}
	};
}
