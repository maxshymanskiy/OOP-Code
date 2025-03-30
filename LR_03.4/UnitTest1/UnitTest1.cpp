#include "pch.h"
#include "CppUnitTest.h"
#include "../SymString.h"
#include "../SymString.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestSymStringConstructor_ValidInput)
		{
			SymString sym("id", "value");
			Assert::AreEqual(std::string("id"), sym.getId());
			Assert::AreEqual(std::string("value"), sym.getValue());
		}
		TEST_METHOD(TestGetId)
		{
			SymString sym("id", "value");
			Assert::AreEqual(std::string("id"), sym.getId());
		}

		TEST_METHOD(TestGetValue)
		{
			SymString sym("id", "value");
			Assert::AreEqual(std::string("value"), sym.getValue());
		}

		TEST_METHOD(TestSetValue_ValidInput)
		{
			SymString sym("id", "value");
			sym.setValue("newValue");
			Assert::AreEqual(std::string("newValue"), sym.getValue());
		}
		
		TEST_METHOD(TestSetValue_EmptyString)
		{
			SymString sym("id", "value");
			try {
				sym.setValue("");
			}
			catch (const std::invalid_argument& e) {
				Assert::AreEqual("Помилка: рядок не може бути порожнім", e.what());
			}
		}

		TEST_METHOD(TestShowBin)
		{
			SymString sym("id", "value");
			Assert::AreEqual(std::string("01110110 01100001 01101100 01110101 01100101 "), sym.showBin());
		}
		
	};
}
