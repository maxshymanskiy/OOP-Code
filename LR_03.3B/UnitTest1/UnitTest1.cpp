#include "pch.h"
#include "CppUnitTest.h"
#include "../Fraction.h"
#include "../Fraction.cpp"
#include "../Pair.h"
#include "../Pair.cpp"

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
			Assert::AreEqual(0, static_cast<int>(f.getFractional()));
		}

		TEST_METHOD(TestParameterizedConstructor)
		{
			Fraction f(3, 50000);
			Assert::AreEqual(3L, f.getWhole());
			Assert::AreEqual(50000, static_cast<int>(f.getFractional()));
		}

		TEST_METHOD(TestCopyConstructor)
		{
			Fraction f1(3, 50000);
			Fraction f2(f1);
			Assert::AreEqual(3L, f2.getWhole());
			Assert::AreEqual(50000, static_cast<int>(f2.getFractional()));
		}

		TEST_METHOD(TestSetWhole)
		{
			Fraction f;
			Assert::IsTrue(f.setWhole(5));
			Assert::AreEqual(5L, f.getWhole());
		}

		TEST_METHOD(TestSetFractional)
		{
			Fraction f;
			Assert::IsTrue(f.setFractional(40000));
			Assert::AreEqual(40000, static_cast<int>(f.getFractional()));
		}
	
	};
}
