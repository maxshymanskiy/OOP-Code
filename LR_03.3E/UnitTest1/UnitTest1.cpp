#include "pch.h"
#include "CppUnitTest.h"
#include "../Vector3D.h"
#include "../Vector3D.cpp"
#include "../Triad.h"
#include "../Triad.cpp"
#include "../Object.h"
#include "../Object.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestVector3DDefaultConstructor)
		{
			Vector3D vec;
			Assert::AreEqual(0, vec.getX());
			Assert::AreEqual(0, vec.getY());
			Assert::AreEqual(0, vec.getZ());
		}

		TEST_METHOD(TestVector3DCopyConstructor)
		{
			Vector3D vec1;
			vec1.setX(1);
			vec1.setY(2);
			vec1.setZ(3);
			Vector3D vec2(vec1);
			Assert::AreEqual(1, vec2.getX());
			Assert::AreEqual(2, vec2.getY());
			Assert::AreEqual(3, vec2.getZ());
		}

		TEST_METHOD(TestVector3DAssignmentOperator)
		{
			Vector3D vec1;
			vec1.setX(4);
			vec1.setY(5);
			vec1.setZ(6);
			Vector3D vec2;
			vec2 = vec1;
			Assert::AreEqual(4, vec2.getX());
			Assert::AreEqual(5, vec2.getY());
			Assert::AreEqual(6, vec2.getZ());
		}

		TEST_METHOD(TestVector3DAdditionOperator)
		{
			Vector3D vec1;
			vec1.setX(1);
			vec1.setY(2);
			vec1.setZ(3);
			Vector3D vec2;
			vec2.setX(4);
			vec2.setY(5);
			vec2.setZ(6);
			Vector3D vec3 = vec1 + vec2;
			Assert::AreEqual(5, vec3.getX());
			Assert::AreEqual(7, vec3.getY());
			Assert::AreEqual(9, vec3.getZ());
		}

		TEST_METHOD(TestVector3DDotProductOperator)
		{
			Vector3D vec1;
			vec1.setX(1);
			vec1.setY(2);
			vec1.setZ(3);
			Vector3D vec2;
			vec2.setX(4);
			vec2.setY(5);
			vec2.setZ(6);
			int dotProduct = vec1 * vec2;
			Assert::AreEqual(32, dotProduct);
		}
	};
}
