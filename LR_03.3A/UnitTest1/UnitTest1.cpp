#include "pch.h"
#include "CppUnitTest.h"
#include "../PublicFraction.h"
#include "../PublicFraction.cpp"
#include "../BaseFraction.h"
#include "../BaseFraction.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestEqualityOperator)
		{
			PublicFraction f1(1, 50000);
			PublicFraction f2(1, 50000);
			Assert::IsTrue(f1 == f2);
		}

		TEST_METHOD(TestInequalityOperator)
		{
			PublicFraction f1(1, 50000);
			PublicFraction f2(2, 50000);
			Assert::IsTrue(f1 != f2);
		}

		TEST_METHOD(TestLessThanOperator)
		{
			PublicFraction f1(1, 50000);
			PublicFraction f2(2, 50000);
			Assert::IsTrue(f1 < f2);
		}

		TEST_METHOD(TestGreaterThanOperator)
		{
			PublicFraction f1(2, 50000);
			PublicFraction f2(1, 50000);
			Assert::IsTrue(f1 > f2);
		}

		TEST_METHOD(TestLessThanOrEqualOperator)
		{
			PublicFraction f1(1, 50000);
			PublicFraction f2(1, 50000);
			Assert::IsTrue(f1 <= f2);
		}
	};
}
