#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_07.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			vector<int> testVector = { 1, 2, 3, 4, 5 };
			int result = findMaxOdd(testVector);
			Assert::AreEqual(5, result);
		}
		TEST_METHOD(TestMethod2)
		{
			vector<int> testVector = { 2, 4, 6, 8 };
			int result = findMaxOdd(testVector);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(TestMethod3)
		{
			vector<int> testVector = { -1, -3, -5 };
			int result = findMaxOdd(testVector);
			Assert::AreEqual(-1, result);
		}
	};
}
