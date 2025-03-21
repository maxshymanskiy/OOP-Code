#include "pch.h"
#include "CppUnitTest.h"
#include "../Vector3D_public.h"
#include "../Vector3D_public.cpp"
#include "../Triad.h"
#include "../Triad.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestDefaultConstructor)
		{
			Vector3D_public vec;
			Assert::AreEqual(0, vec.getX());
			Assert::AreEqual(0, vec.getY());
			Assert::AreEqual(0, vec.getZ());
		}

		TEST_METHOD(TestParameterizedConstructor)
		{
			Triad triad(1, 2, 3);
			Vector3D_public vec(triad);
			Assert::AreEqual(1, vec.getX());
			Assert::AreEqual(2, vec.getY());
			Assert::AreEqual(3, vec.getZ());
		}

		TEST_METHOD(TestCopyConstructor)
		{
			Vector3D_public vec1(Triad(1, 2, 3));
			Vector3D_public vec2(vec1);
			Assert::AreEqual(1, vec2.getX());
			Assert::AreEqual(2, vec2.getY());
			Assert::AreEqual(3, vec2.getZ());
		}

		TEST_METHOD(TestAssignmentOperator)
		{
			Vector3D_public vec1(Triad(1, 2, 3));
			Vector3D_public vec2;
			vec2 = vec1;
			Assert::AreEqual(1, vec2.getX());
			Assert::AreEqual(2, vec2.getY());
			Assert::AreEqual(3, vec2.getZ());
		}

		TEST_METHOD(TestAdditionOperator)
		{
			Vector3D_public vec1(Triad(1, 2, 3));
			Vector3D_public vec2(Triad(4, 5, 6));
			Vector3D_public result = vec1 + vec2;
			Assert::AreEqual(5, result.getX());
			Assert::AreEqual(7, result.getY());
			Assert::AreEqual(9, result.getZ());
		}

		TEST_METHOD(TestDotProductOperator)
		{
			Vector3D_public vec1(Triad(1, 2, 3));
			Vector3D_public vec2(Triad(4, 5, 6));
			int result = vec1 * vec2;
			Assert::AreEqual(32, result); // 1*4 + 2*5 + 3*6 = 32
		}

		TEST_METHOD(TestIncrementOperators)
		{
			Vector3D_public vec(Triad(1, 2, 3));
			++vec;
			Assert::AreEqual(2, vec.getX());
			Assert::AreEqual(3, vec.getY());
			Assert::AreEqual(4, vec.getZ());

			vec++;
			Assert::AreEqual(3, vec.getX());
			Assert::AreEqual(4, vec.getY());
			Assert::AreEqual(5, vec.getZ());
		}

		TEST_METHOD(TestDecrementOperators)
		{
			Vector3D_public vec(Triad(1, 2, 3));
			--vec;
			Assert::AreEqual(0, vec.getX());
			Assert::AreEqual(1, vec.getY());
			Assert::AreEqual(2, vec.getZ());

			vec--;
			Assert::AreEqual(-1, vec.getX());
			Assert::AreEqual(0, vec.getY());
			Assert::AreEqual(1, vec.getZ());
		}

	};
}
