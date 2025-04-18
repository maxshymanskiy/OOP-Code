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

		TEST_METHOD(TestCopyConstructor)
		{
			Fraction f1(3, 54321);
			Fraction f2(f1);
			Assert::AreEqual(3L, f2.getWhole());
			Assert::AreEqual((unsigned short)54321, f2.getFractional());
		}

		TEST_METHOD(TestSetWhole_ValidInput)
		{
			Fraction f;
			Assert::IsTrue(f.setWhole(123));
			Assert::AreEqual(123L, f.getWhole());
		}

		TEST_METHOD(TestSetWhole_Overflow)
		{
			Fraction f;
			auto func = [&]() { f.setWhole(std::numeric_limits<long>::max()); };
			Assert::ExpectException<FractionOverflowException>(func);
		}

		TEST_METHOD(TestSetFractional_ValidInput)
		{
			Fraction f;
			Assert::IsTrue(f.setFractional(54321));
			Assert::AreEqual((unsigned short)54321, f.getFractional());
		}
	};
}
