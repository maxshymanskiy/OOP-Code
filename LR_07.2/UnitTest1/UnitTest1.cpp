#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_07.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestRandomNumber)
		{
			for (int i = 0; i < 100; ++i) {
				int num = RandomNumber();
				Assert::IsTrue(num >= -50 && num <= 49, L"RandomNumber is out of range");
			}
		}

		TEST_METHOD(TestCreateList)
		{
			int size = 10;
			list<int> lst = createList(size);
			Assert::AreEqual(size, (int)lst.size(), L"List size is incorrect");

			for (int num : lst) {
				Assert::IsTrue(num >= -50 && num <= 49, L"List contains a number out of range");
			}
		}

		TEST_METHOD(TestReverseList)
		{
			list<int> originalList = { 1, 2, 3, 4, 5 };
			list<int> reversedList = reverseList(originalList);

			list<int> expectedReversedList = { 5, 4, 3, 2, 1 };
			Assert::IsTrue(reversedList == expectedReversedList, L"Reversed list is incorrect");
		}

		TEST_METHOD(TestPrintList)
		{
			list<int> lst = { 1, 2, 3 };
			printList(lst); 
		}
		
	};
}
