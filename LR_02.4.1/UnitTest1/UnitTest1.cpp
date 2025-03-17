#include "pch.h"
#include "CppUnitTest.h"
#include "../Matrix.h"  // Adjust the path as necessary
#include "../Matrix.cpp"  // Adjust the path as necessary


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(MatrixTest)
	{
	public:

		TEST_METHOD(DefaultConstructor)
		{
			Matrix m;
			Assert::AreEqual(0, m.getSize());
		}

		TEST_METHOD(ConstructorWithSize)
		{
			Assert::ExpectException<std::invalid_argument>([]() { Matrix m(-1); });
			Matrix m(3);
			Assert::AreEqual(3, m.getSize());
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					Assert::AreEqual(0, m.getElement(i, j));
				}
			}
		}

		TEST_METHOD(CopyConstructor)
		{
			Matrix m1(3);
			m1.setElement(1, 1, 5);
			Matrix m2(m1);
			Assert::AreEqual(3, m2.getSize());
			Assert::AreEqual(5, m2.getElement(1, 1));
		}

		TEST_METHOD(GetSize)
		{
			Matrix m(4);
			Assert::AreEqual(4, m.getSize());
		}

		TEST_METHOD(SetSize)
		{
			Matrix m;
			m.setSize(2);
			Assert::AreEqual(2, m.getSize());
			Assert::ExpectException<std::invalid_argument>([&m]() { m.setSize(-1); });
		}

		TEST_METHOD(GetSetElement)
		{
			Matrix m(3);
			m.setElement(1, 1, 10);
			Assert::AreEqual(10, m.getElement(1, 1));
			Assert::ExpectException<std::out_of_range>([&m]() { m.getElement(3, 3); });
			Assert::ExpectException<std::out_of_range>([&m]() { m.setElement(3, 3, 10); });
		}

		TEST_METHOD(OperatorEqual)
		{
			Matrix m1(2);
			Matrix m2(2);
			Assert::IsTrue(m1 == m2);
			m1.setElement(0, 0, 1);
			Assert::IsFalse(m1 == m2);
		}

		TEST_METHOD(OperatorNotEqual)
		{
			Matrix m1(2);
			Matrix m2(2);
			Assert::IsFalse(m1 != m2);
			m1.setElement(0, 0, 1);
			Assert::IsTrue(m1 != m2);
		}

		TEST_METHOD(OperatorAssignment)
		{
			Matrix m1(2);
			m1.setElement(0, 0, 1);
			Matrix m2 = m1;
			Assert::AreEqual(1, m2.getElement(0, 0));
		}

		TEST_METHOD(OperatorMultiplication)
		{
			Matrix m1(2);
			Matrix m2(2);
			m1.setElement(0, 0, 1);
			m1.setElement(0, 1, 2);
			m1.setElement(1, 0, 3);
			m1.setElement(1, 1, 4);
			m2.setElement(0, 0, 2);
			m2.setElement(0, 1, 0);
			m2.setElement(1, 0, 1);
			m2.setElement(1, 1, 2);
			Matrix result = m1 * m2;
			Assert::AreEqual(4, result.getElement(0, 0));
			Assert::AreEqual(4, result.getElement(0, 1));
			Assert::AreEqual(10, result.getElement(1, 0));
			Assert::AreEqual(8, result.getElement(1, 1));
		}

		TEST_METHOD(OperatorIndexing)
		{
			Matrix m(2);
			m[0][0] = 1;
			Assert::AreEqual(1, m[0][0]);
			Assert::ExpectException<std::out_of_range>([&m]() { m[2][0]; });
		}

		TEST_METHOD(Norm)
		{
			Matrix m(2);
			m.setElement(0, 0, -1);
			m.setElement(1, 1, 3);
			Assert::AreEqual(4, m.norm());
		}

		TEST_METHOD(OperatorStream)
		{
			Matrix m(2);
			m.setElement(0, 0, 1);
			m.setElement(1, 1, 2);
			std::ostringstream oss;
			oss << m;
			Assert::AreEqual(std::string("1\t0\t\n0\t2\t\n"), oss.str());

			std::istringstream iss("2\n1 0\n0 2\n");
			Matrix m2;
			iss >> m2;
			Assert::AreEqual(1, m2.getElement(0, 0));
			Assert::AreEqual(2, m2.getElement(1, 1));
		}
	};
}
