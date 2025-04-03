#include "pch.h"
#include "CppUnitTest.h"
#include "../Cube.h"
#include "../Cube.cpp"
#include "../Parallelepiped.h"
#include "../Parallelepiped.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestSurfaceArea)
		{
			// Arrange
			double side = 3.0;
			Cube cube(side);
			double expectedSurfaceArea = 6 * side * side;

			// Act
			double actualSurfaceArea = cube.surface_area();

			// Assert
			Assert::AreEqual(expectedSurfaceArea, actualSurfaceArea, L"Surface area calculation is incorrect");
		}

		TEST_METHOD(TestSurfaceAreaNegative)
		{
			// Arrange
			double side = -3.0;
			Cube cube(side);
			double expectedSurfaceArea = 6 * side * side;
			// Act
			double actualSurfaceArea = cube.surface_area();
			// Assert
			Assert::AreEqual(expectedSurfaceArea, actualSurfaceArea, L"Surface area calculation is incorrect for negative side length");
		}

		TEST_METHOD(TestParallelepipedSurfaceArea)
		{
			// Arrange
			double x = 3.0;
			double y = 4.0;
			double z = 5.0;
			Parallelepiped parallelepiped(x, y, z);
			double expectedSurfaceArea = 2 * (x * y + x * z + y * z);

			// Act
			double actualSurfaceArea = parallelepiped.surface_area();

			// Assert
			Assert::AreEqual(expectedSurfaceArea, actualSurfaceArea, L"Surface area calculation is incorrect");
		}
	};
}
