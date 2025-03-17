#include "pch.h"
#include "CppUnitTest.h"
#include "../Vector3D.h"
#include "../Vector3D.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestTriadParameterizedConstructor)
		{
			Vector3D::Triad t(1, 2, 3);
			Assert::AreEqual(1, t.getX());
			Assert::AreEqual(2, t.getY());
			Assert::AreEqual(3, t.getZ());
		}

		TEST_METHOD(TestTriadCopyConstructor)
		{
			Vector3D::Triad t1(1, 2, 3);
			Vector3D::Triad t2(t1);
			Assert::AreEqual(1, t2.getX());
			Assert::AreEqual(2, t2.getY());
			Assert::AreEqual(3, t2.getZ());
		}

		TEST_METHOD(TestTriadAddition)
		{
			Vector3D::Triad t1(1, 2, 3);
			Vector3D::Triad t2(4, 5, 6);
			Vector3D::Triad t3 = t1 + t2;
			Assert::AreEqual(5, t3.getX());
			Assert::AreEqual(7, t3.getY());
			Assert::AreEqual(9, t3.getZ());
		}

		TEST_METHOD(TestTriadMultiplication)
		{
			Vector3D::Triad t(1, 2, 3);
			Vector3D::Triad t2 = t * 2;
			Assert::AreEqual(2, t2.getX());
			Assert::AreEqual(4, t2.getY());
			Assert::AreEqual(6, t2.getZ());
		}

		TEST_METHOD(TestTriadEquality)
		{
			Vector3D::Triad t1(1, 2, 3);
			Vector3D::Triad t2(1, 2, 3);
			Assert::IsTrue(t1 == t2);
		}

		TEST_METHOD(TestTriadIncrementPrefix)
		{
			Vector3D::Triad t(1, 2, 3);
			++t;
			Assert::AreEqual(2, t.getX());
			Assert::AreEqual(3, t.getY());
			Assert::AreEqual(4, t.getZ());
		}

		TEST_METHOD(TestTriadIncrementPostfix)
		{
			Vector3D::Triad t(1, 2, 3);
			Vector3D::Triad t2 = t++;
			Assert::AreEqual(1, t2.getX());
			Assert::AreEqual(2, t2.getY());
			Assert::AreEqual(3, t2.getZ());
			Assert::AreEqual(2, t.getX());
			Assert::AreEqual(3, t.getY());
			Assert::AreEqual(4, t.getZ());
		}

		TEST_METHOD(TestTriadDecrementPrefix)
		{
			Vector3D::Triad t(1, 2, 3);
			--t;
			Assert::AreEqual(0, t.getX());
			Assert::AreEqual(1, t.getY());
			Assert::AreEqual(2, t.getZ());
		}
	};
}
