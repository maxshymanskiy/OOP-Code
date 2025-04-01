#include "pch.h"
#include "CppUnitTest.h"
#include "../B1.h"
#include "../B1.cpp"
#include "../B2.h"
#include "../B2.cpp"
#include "../D1.h"
#include "../D2.h"
#include "../D2.cpp"
#include "../D1.cpp"
#include "../D4.h"
#include "../D4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestShow)
		{
			int value = 20;
			B1 b1(value);
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
			b1.show();
			std::cout.rdbuf(old);
			std::string expectedOutput = "B1: b1 = 20\n";
			Assert::AreEqual(expectedOutput, buffer.str());
		}

		TEST_METHOD(TestD1Show)
		{
			int x = 10, y = 20, z = 30;
			D1 d1(x, y, z);
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
			d1.show();
			std::cout.rdbuf(old);
			std::string expectedOutput = "B1: b1 = 20\nB2: b2 = 30\nD1: d1 = 10\n";
			Assert::AreEqual(expectedOutput, buffer.str());
		}

		TEST_METHOD(TestD4Show)
		{
			int x = 10, y = 20, z = 30, w = 40, v = 50;
			D4 d4(x, y, z, w, v);
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
			d4.show();
			std::cout.rdbuf(old);
			std::string expectedOutput = "B1: b1 = 40\nB2: b2 = 50\nD1: d1 = 30\nD2: d2 = 20\nD4: d4 = 10\n";
			Assert::AreEqual(expectedOutput, buffer.str());
		}
	};
}
