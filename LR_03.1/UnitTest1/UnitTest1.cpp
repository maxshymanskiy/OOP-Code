#include "pch.h"
#include "CppUnitTest.h"
#include "../Triad.h"
#include "../Triad.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestConstructor)
		{
			Triad t(1, 2, 3);
			Assert::AreEqual(1, t.getX());
			Assert::AreEqual(2, t.getY());
			Assert::AreEqual(3, t.getZ());
		}

		TEST_METHOD(TestCopyConstructor)
		{
			Triad t1(1, 2, 3);
			Triad t2(t1);
			Assert::AreEqual(1, t2.getX());
			Assert::AreEqual(2, t2.getY());
			Assert::AreEqual(3, t2.getZ());
		}

		TEST_METHOD(TestGetters)
		{
			Triad t(4, 5, 6);
			Assert::AreEqual(4, t.getX());
			Assert::AreEqual(5, t.getY());
			Assert::AreEqual(6, t.getZ());
		}

		TEST_METHOD(TestSetters)
		{
			Triad t;
			t.setX(7);
			t.setY(8);
			t.setZ(9);
			Assert::AreEqual(7, t.getX());
			Assert::AreEqual(8, t.getY());
			Assert::AreEqual(9, t.getZ());
		}

		TEST_METHOD(TestOperatorPlus)
		{
			Triad t(1, 2, 3);
			Triad result = t + 5;
			Assert::AreEqual(6, result.getX());
			Assert::AreEqual(7, result.getY());
			Assert::AreEqual(8, result.getZ());
		}

		TEST_METHOD(TestOperatorMultiply)
		{
			Triad t(1, 2, 3);
			Triad result = t * 2;
			Assert::AreEqual(2, result.getX());
			Assert::AreEqual(4, result.getY());
			Assert::AreEqual(6, result.getZ());
		}

		TEST_METHOD(TestOperatorEquals)
		{
			Triad t1(1, 2, 3);
			Triad t2(1, 2, 3);
			Assert::IsTrue(t1 == t2);
		}

		TEST_METHOD(TestOperatorIncrementPrefix)
		{
			Triad t(1, 2, 3);
			++t;
			Assert::AreEqual(2, t.getX());
			Assert::AreEqual(3, t.getY());
			Assert::AreEqual(4, t.getZ());
		}

		TEST_METHOD(TestOperatorIncrementPostfix)
		{
			Triad t(1, 2, 3);
			Triad result = t++;
			Assert::AreEqual(1, result.getX());
			Assert::AreEqual(2, result.getY());
			Assert::AreEqual(3, result.getZ());
			Assert::AreEqual(2, t.getX());
			Assert::AreEqual(3, t.getY());
			Assert::AreEqual(4, t.getZ());
		}

		TEST_METHOD(TestOperatorDecrementPrefix)
		{
			Triad t(1, 2, 3);
			--t;
			Assert::AreEqual(0, t.getX());
			Assert::AreEqual(1, t.getY());
			Assert::AreEqual(2, t.getZ());
		}
	};
}
