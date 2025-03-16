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
            set.addElement(10); // �������, �� ������� ��������

            Assert::AreEqual((size_t)2, set.getSize()); // ���������� ������� ��������
            Assert::IsTrue(10 ^ set); // ���������� �������� �������� 10
            Assert::IsTrue(20 ^ set); // ���������� �������� �������� 20
        }

        TEST_METHOD(TestRemoveElement)
        {
            IntegerSet set;
            set.addElement(10);
            set.addElement(20);
            set.removeElement(10);

            Assert::AreEqual((size_t)1, set.getSize()); // ���������� ������� ��������
            Assert::IsFalse(10 ^ set); // ����������, �� ������� 10 ��������
            Assert::IsTrue(20 ^ set);  // ����������, �� ������� 20 ���������
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

            Assert::IsTrue(setA == setB); // setA � setB �������
            Assert::IsFalse(setA == setC); // setA � setC ���
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

            Assert::IsTrue(setA != setB); // setA � setB ���
        }

	};
}
