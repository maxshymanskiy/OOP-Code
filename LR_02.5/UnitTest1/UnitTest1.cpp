#include "pch.h"
#include "CppUnitTest.h"
#include "../Triad.h"
#include "../Triad.cpp"
#include "../Vector3D.h"
#include "../Vector3D.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestParameterizedConstructor)
		{
			Triad triad(1, 2, 3);
			Vector3D vec(triad);
			Triad result = vec.getTriad();
			Assert::AreEqual(1, result.getX());
			Assert::AreEqual(2, result.getY());
			Assert::AreEqual(3, result.getZ());
		}

		TEST_METHOD(TestCopyConstructor)
		{
			Triad triad(1, 2, 3);
			Vector3D vec1(triad);
			Vector3D vec2(vec1);
			Triad result = vec2.getTriad();
			Assert::AreEqual(1, result.getX());
			Assert::AreEqual(2, result.getY());
			Assert::AreEqual(3, result.getZ());
		}

		TEST_METHOD(TestGetTriad)
		{
			Triad triad(1, 2, 3);
			Vector3D vec(triad);
			Triad result = vec.getTriad();
			Assert::AreEqual(1, result.getX());
			Assert::AreEqual(2, result.getY());
			Assert::AreEqual(3, result.getZ());
		}

		TEST_METHOD(TestSetTriad)
		{
			Vector3D vec;
			Triad triad(1, 2, 3);
			vec.setTriad(triad);
			Triad result = vec.getTriad();
			Assert::AreEqual(1, result.getX());
			Assert::AreEqual(2, result.getY());
			Assert::AreEqual(3, result.getZ());
		}

		TEST_METHOD(TestAssignmentOperator)
		{
			Triad triad1(1, 2, 3);
			Vector3D vec1(triad1);
			Vector3D vec2;
			vec2 = vec1;
			Triad result = vec2.getTriad();
			Assert::AreEqual(1, result.getX());
			Assert::AreEqual(2, result.getY());
			Assert::AreEqual(3, result.getZ());
		}

		TEST_METHOD(TestAdditionOperator)
		{
			Triad triad1(1, 2, 3);
			Triad triad2(4, 5, 6);
			Vector3D vec1(triad1);
			Vector3D vec2(triad2);
			Vector3D result = vec1 + vec2;
			Triad resultTriad = result.getTriad();
			Assert::AreEqual(5, resultTriad.getX());
			Assert::AreEqual(7, resultTriad.getY());
			Assert::AreEqual(9, resultTriad.getZ());
		}
	};
}
