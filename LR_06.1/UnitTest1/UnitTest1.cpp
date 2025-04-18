#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_06.1.cpp"
#include "../Array.h"
#include "../Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestProcessArray_AllPositive)
		{
			Array::value_type input[] = { 10, 20, 30, 40, 50 };
			int size = 5;

			Array result = processArray(input, size);

			Assert::AreEqual(size + 2, (int)result.size()); // Original size + sum + abs_mean
			Assert::AreEqual(150.0, result[size]); // Sum
			Assert::AreEqual(30.0, result[size + 1]); // Abs mean
		}

        TEST_METHOD(TestProcessArray)
        {
            const int size = 14;
            Array::value_type testArray[size] = { 8, 8, -12, -13, 28, 36, -47, -15, -49, -6, -9, -31, -12, 31 };

            Array::value_type maxValue = testArray[0];
            for (int i = 1; i < size; i++) {
                if (testArray[i] > maxValue) {
                    maxValue = testArray[i];
                }
            }

            Array result = processArray(testArray, size);
            Assert::AreEqual(size + 2, (int)result.size(), L"Result size should be input size + 2");
            Array::value_type halfMax = maxValue / 2;
            int negCount = 0;

            Assert::AreEqual(8.0, result[0], L"Element at index 0 is incorrect");
            Assert::AreEqual(8.0, result[1], L"Element at index 1 is incorrect");
            Assert::AreEqual(-12.0, result[2], L"Element at index 2 is incorrect");
            Assert::AreEqual(halfMax, result[3], L"Element at index 3 is incorrect");
            Assert::AreEqual(28.0, result[4], L"Element at index 4 is incorrect");
            Assert::AreEqual(36.0, result[5], L"Element at index 5 is incorrect");
            Assert::AreEqual(-47.0, result[6], L"Element at index 6 is incorrect");
            Assert::AreEqual(halfMax, result[7], L"Element at index 7 is incorrect");
            Assert::AreEqual(-49.0, result[8], L"Element at index 8 is incorrect");
            Assert::AreEqual(halfMax, result[9], L"Element at index 9 is incorrect");
            Assert::AreEqual(-9.0, result[10], L"Element at index 10 is incorrect");
            Assert::AreEqual(halfMax, result[11], L"Element at index 11 is incorrect");
            Assert::AreEqual(-12.0, result[12], L"Element at index 12 is incorrect");
            Assert::AreEqual(31.0, result[13], L"Element at index 13 is incorrect");

            Array::value_type expectedSum = 0;
            for (int i = 0; i < size; i++) {
                // Count negative numbers and apply the transformation
                if (testArray[i] < 0) {
                    negCount++;
                    if (negCount % 2 == 0) {
                        expectedSum += halfMax; // Add the transformed value
                    }
                    else {
                        expectedSum += testArray[i]; // Add the original value
                    }
                }
                else {
                    expectedSum += testArray[i]; // Add the non-negative value
                }
            }

            // Check sum (the second-to-last element)
            Assert::AreEqual(expectedSum, result[size], L"Sum value is incorrect");

            // Calculate expected absolute mean
            Array::value_type expectedAbsSum = 0;
            for (int i = 0; i < size; i++) {
                if (testArray[i] < 0) {
                    negCount = 0; // Reset for this calculation
                    for (int j = 0; j <= i; j++) {
                        if (testArray[j] < 0) {
                            negCount++;
                            if (negCount % 2 == 0) {
                                expectedAbsSum += std::abs(halfMax);
                                break;
                            }
                        }
                    }

                    if (negCount % 2 != 0) {
                        expectedAbsSum += std::abs(testArray[i]);
                    }
                }
                else {
                    expectedAbsSum += std::abs(testArray[i]);
                }
            }

            Array::value_type expectedAbsMean = expectedAbsSum / size;

            // A simpler way to calculate the expected absolute mean for the test case
            Array::value_type simplifiedAbsMean = 22.2857;

            // Check absolute mean (the last element)
            Assert::AreEqual(simplifiedAbsMean, result[size + 1], 0.0001, L"Absolute mean value is incorrect");
        }

        TEST_METHOD(TestSingleElementArray)
        {
            // Arrange
            const int size = 1;
            Array::value_type testArray[size] = { 10 };

            // Act
            Array result = processArray(testArray, size);

            // Assert
            Assert::AreEqual(size + 2, (int)result.size(), L"Result size should be input size + 2");
            Assert::AreEqual(10.0, result[0], L"Element at index 0 is incorrect");
            Assert::AreEqual(10.0, result[1], L"Sum should be equal to the single element");
            Assert::AreEqual(10.0, result[2], L"Absolute mean should be equal to the single element");
        }

        TEST_METHOD(TestAllNegativeArray)
        {
            // Arrange
            const int size = 6;
            Array::value_type testArray[size] = { -10, -20, -30, -40, -50, -60 };

            // Find the maximum value
            Array::value_type maxValue = testArray[0];
            for (int i = 1; i < size; i++) {
                if (testArray[i] > maxValue) {
                    maxValue = testArray[i];
                }
            }

            // Act
            Array result = processArray(testArray, size);

            // Assert
            Assert::AreEqual(size + 2, (int)result.size(), L"Result size should be input size + 2");

            // Every second negative should be replaced
            Array::value_type halfMax = maxValue / 2;
            Assert::AreEqual(-10.0, result[0], L"Element at index 0 is incorrect");
            Assert::AreEqual(halfMax, result[1], L"Element at index 1 is incorrect");
            Assert::AreEqual(-30.0, result[2], L"Element at index 2 is incorrect");
            Assert::AreEqual(halfMax, result[3], L"Element at index 3 is incorrect");
            Assert::AreEqual(-50.0, result[4], L"Element at index 4 is incorrect");
            Assert::AreEqual(halfMax, result[5], L"Element at index 5 is incorrect");

            // Calculate expected sum and absolute mean
            Array::value_type expectedSum = -10 + halfMax + (-30) + halfMax + (-50) + halfMax;
            Array::value_type expectedAbsMean = (10 + std::abs(halfMax) + 30 + std::abs(halfMax) + 50 + std::abs(halfMax)) / size;

            // Check sum and absolute mean
            Assert::AreEqual(expectedSum, result[size], L"Sum value is incorrect");
            Assert::AreEqual(expectedAbsMean, result[size + 1], 0.0001, L"Absolute mean value is incorrect");
        }

	};
}
