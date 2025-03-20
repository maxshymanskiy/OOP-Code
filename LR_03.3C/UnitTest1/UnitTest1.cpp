#include "pch.h"
#include "CppUnitTest.h"
#include "../Fraction.h"
#include "../Fraction.cpp"
#include "../Object.h"
#include "../Object.cpp"



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

		TEST_METHOD(TestInitializationConstructor)
		{
			Fraction f(5, 12345);
			Assert::AreEqual(5L, f.getWhole());
			Assert::AreEqual((unsigned short)12345, f.getFractional());
		}

		TEST_METHOD(TestCopyConstructor)
		{
			Fraction f1(5, 12345);
			Fraction f2(f1);
			Assert::AreEqual(5L, f2.getWhole());
			Assert::AreEqual((unsigned short)12345, f2.getFractional());
		}

		TEST_METHOD(TestSetWhole)
		{
			Fraction f;
			f.setWhole(10);
			Assert::AreEqual(10L, f.getWhole());
		}
		
	};
}
