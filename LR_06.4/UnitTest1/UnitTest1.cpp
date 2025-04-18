#include "pch.h"
#include "CppUnitTest.h"
#include <windows.h> // Include Windows API for SLIST_HEADER
#include "../LR_06.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		// ���� ������������ � ������� �������
		TEST_METHOD(TestConstructorWithValidSize)
		{
			ParameterizedArray<int> arr(5);
			Assert::AreEqual(5, arr.getSize());

			// �������� ����������� �� �������������
			for (int i = 0; i < arr.getSize(); i++) {
				Assert::AreEqual(0, arr[i]);
			}
		}

		// ���� ������������ � ��������� �������
		TEST_METHOD(TestConstructorWithInvalidSize)
		{
			auto invalidSize = []() { ParameterizedArray<int> arr(0); };
			Assert::ExpectException<std::exception>(invalidSize);

			auto negativeSize = []() { ParameterizedArray<int> arr(-5); };
			Assert::ExpectException<std::exception>(negativeSize);
		}

		// ���� ������������ ������������
		TEST_METHOD(TestCopyConstructor)
		{
			ParameterizedArray<int> original(3);
			original[0] = 10;
			original[1] = 20;
			original[2] = 30;

			ParameterizedArray<int> copy(original);

			// �������� ������ �� �����
			Assert::AreEqual(original.getSize(), copy.getSize());
			for (int i = 0; i < original.getSize(); i++) {
				Assert::AreEqual(original[i], copy[i]);
			}

			// �������� ����������� ����
			original[1] = 999;
			Assert::AreNotEqual(original[1], copy[1]);
		}

		// ���� ��������� []
		TEST_METHOD(TestIndexOperator)
		{
			ParameterizedArray<int> arr(3);

			// ���� ������
			arr[0] = 100;
			arr[1] = 200;
			arr[2] = 300;

			// ���� �������
			Assert::AreEqual(100, arr[0]);
			Assert::AreEqual(200, arr[1]);
			Assert::AreEqual(300, arr[2]);

			// ���� ������ �� ��� - ���������� ������
			auto negativeIndex = [&arr]() { arr[-1]; };
			Assert::ExpectException<std::exception>(negativeIndex);

			// ���� ������ �� ��� - ������ >= size
			auto largeIndex = [&arr]() { arr[3]; };
			Assert::ExpectException<std::exception>(largeIndex);
		}
	};
}
