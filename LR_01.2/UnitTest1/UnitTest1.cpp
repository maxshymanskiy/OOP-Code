#include "pch.h"
#include "CppUnitTest.h"
#include "../BigInteger.h"
#include "../BigInteger.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

        TEST_METHOD(TestInit_ValidNumber)
        {
            BigInteger bigInt;
            bool result = bigInt.Init("12345");
            Assert::IsTrue(result);
            Assert::AreEqual(std::string("12345"), bigInt.getNumber());
        }

        TEST_METHOD(TestInit_InvalidNumber)
        {
            BigInteger bigInt;
            bool result = bigInt.Init("12a45");
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestInit_EmptyString)
        {
            BigInteger bigInt;
            bool result = bigInt.Init("");
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestInit_LeadingZeros)
        {
            BigInteger bigInt;
            bool result = bigInt.Init("000123");
            Assert::IsTrue(result);
            Assert::AreEqual(std::string("123"), bigInt.getNumber());
        }

        TEST_METHOD(TestOperatorEquals)
        {
            BigInteger bigInt1 = makeBigInteger("123");
            BigInteger bigInt2 = makeBigInteger("123");
            BigInteger bigInt3 = makeBigInteger("124");

            Assert::IsTrue(bigInt1 == bigInt2);
            Assert::IsFalse(bigInt1 == bigInt3);
        }

        TEST_METHOD(TestOperatorLessThan)
        {
            BigInteger bigInt1 = makeBigInteger("123");
            BigInteger bigInt2 = makeBigInteger("124");
            BigInteger bigInt3 = makeBigInteger("1234");

            Assert::IsTrue(bigInt1 < bigInt2);
            Assert::IsTrue(bigInt1 < bigInt3);
            Assert::IsFalse(bigInt2 < bigInt1);
        }

        TEST_METHOD(TestOperatorGreaterThan)
        {
            BigInteger bigInt1 = makeBigInteger("124");
            BigInteger bigInt2 = makeBigInteger("123");
            BigInteger bigInt3 = makeBigInteger("1234");

            Assert::IsTrue(bigInt1 > bigInt2);
            Assert::IsTrue(bigInt3 > bigInt1);
            Assert::IsFalse(bigInt2 > bigInt1);
        }

        TEST_METHOD(TestMakeBigInteger_Valid)
        {
            BigInteger bigInt = makeBigInteger("12345");
            Assert::AreEqual(std::string("12345"), bigInt.getNumber());
        }
	};
}
