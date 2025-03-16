#include "pch.h"
#include "CppUnitTest.h"
#include "../IntegerSet.h"
#include "../IntegerSet.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestAddElement)
        {
            IntegerSet set;
            set.addElement(10);
            set.addElement(20);
            set.addElement(10); // Дублікат, не повинен додатися

            Assert::AreEqual((size_t)2, set.getSize()); // Перевіряємо кількість елементів
            Assert::IsTrue(10 ^ set); // Перевіряємо наявність елемента 10
            Assert::IsTrue(20 ^ set); // Перевіряємо наявність елемента 20
        }

        TEST_METHOD(TestRemoveElement)
        {
            IntegerSet set;
            set.addElement(10);
            set.addElement(20);
            set.removeElement(10);

            Assert::AreEqual((size_t)1, set.getSize()); // Перевіряємо кількість елементів
            Assert::IsFalse(10 ^ set); // Перевіряємо, що елемент 10 видалено
            Assert::IsTrue(20 ^ set);  // Перевіряємо, що елемент 20 залишився
        }

        TEST_METHOD(TestEquality)
        {
            IntegerSet setA;
            setA.addElement(1);
            setA.addElement(2);
            setA.addElement(3);

            IntegerSet setB;
            setB.addElement(1);
            setB.addElement(2);
            setB.addElement(3);

            IntegerSet setC;
            setC.addElement(1);
            setC.addElement(2);
            setC.addElement(4);

            Assert::IsTrue(setA == setB); // setA і setB однакові
            Assert::IsFalse(setA == setC); // setA і setC різні
        }

        TEST_METHOD(TestInequality)
        {
            IntegerSet setA;
            setA.addElement(1);
            setA.addElement(2);
            setA.addElement(3);

            IntegerSet setB;
            setB.addElement(1);
            setB.addElement(2);
            setB.addElement(4);

            Assert::IsTrue(setA != setB); // setA і setB різні
        }

	};
}
