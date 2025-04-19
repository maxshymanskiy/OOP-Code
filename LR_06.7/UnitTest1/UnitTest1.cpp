#include "pch.h"
#include "CppUnitTest.h"
#include "../Array.h"
#include "../Array.cpp"
#include "../LR_06.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestReverseCopy)
		{
			// Arrange
			const int size = 5;
			Array inputArray(size);
			for (int i = 0; i < size; i++) {
				inputArray[i] = i + 1; // {1, 2, 3, 4, 5}
			}
			Array expected(size);
			expected[0] = 5;
			expected[1] = 4;
			expected[2] = 3;
			expected[3] = 2;
			expected[4] = 1;

			Array result(size);

			// Act
			reverse_copy(inputArray.begin(), inputArray.end(), result.begin());

			// Assert
			for (int i = 0; i < size; i++) {
				Assert::AreEqual(expected[i], result[i], L"Mismatch in reverse_copy result");
			}
		}

		TEST_METHOD(TestReverseCopyIf)
		{
			// Arrange
			const int size = 5;
			Array inputArray(size);
			inputArray[0] = -10;
			inputArray[1] = 20;
			inputArray[2] = -30;
			inputArray[3] = 40;
			inputArray[4] = -50;

			Array expected(size);
			expected[0] = -50;
			expected[1] = -30;
			expected[2] = -10;
			expected[3] = 0; // Remaining elements are 0
			expected[4] = 0;

			Array result(size);
			result.assign(0); // Initialize with zeros

			NegativeValuePredicate<Array::value_type> negPred;

			// Act
			reverse_copy_if(inputArray.begin(), inputArray.end(), result.begin(), negPred);

			// Assert
			for (int i = 0; i < size; i++) {
				Assert::AreEqual(expected[i], result[i], L"Mismatch in reverse_copy_if result");
			}
		}
	};
}
