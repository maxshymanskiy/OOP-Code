#include "pch.h"
#include "CppUnitTest.h"
#include "../Book.h"
#include "../Book.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestDefaultConstructor)
		{
			Book book;
			Assert::AreEqual(std::string(""), book.getAuthor());
			Assert::AreEqual(std::string(""), book.getTitle());
			Assert::AreEqual(0, book.getYear());
			Assert::AreEqual(std::string(""), book.getPublisher());
			Assert::AreEqual(0.0, book.getPrice());
		}

		TEST_METHOD(TestParameterizedConstructor)
		{
			Book book("Author", "Title", 2025, "Publisher", 19.99);
			Assert::AreEqual(std::string("Author"), book.getAuthor());
			Assert::AreEqual(std::string("Title"), book.getTitle());
			Assert::AreEqual(2025, book.getYear());
			Assert::AreEqual(std::string("Publisher"), book.getPublisher());
			Assert::AreEqual(19.99, book.getPrice());
		}

		TEST_METHOD(TestCopyConstructor)
		{
			Book book1("Author", "Title", 2025, "Publisher", 19.99);
			Book book2(book1);
			Assert::AreEqual(book1.getAuthor(), book2.getAuthor());
			Assert::AreEqual(book1.getTitle(), book2.getTitle());
			Assert::AreEqual(book1.getYear(), book2.getYear());
			Assert::AreEqual(book1.getPublisher(), book2.getPublisher());
			Assert::AreEqual(book1.getPrice(), book2.getPrice());
		}

		TEST_METHOD(TestSettersAndGetters)
		{
			Book book;
			book.setAuthor("New Author");
			book.setTitle("New Title");
			book.setYear(2025);
			book.setPublisher("New Publisher");
			book.setPrice(29.99);

			Assert::AreEqual(std::string("New Author"), book.getAuthor());
			Assert::AreEqual(std::string("New Title"), book.getTitle());
			Assert::AreEqual(2025, book.getYear());
			Assert::AreEqual(std::string("New Publisher"), book.getPublisher());
			Assert::AreEqual(29.99, book.getPrice());
		}
	};
}
