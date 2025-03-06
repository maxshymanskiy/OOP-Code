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
	
        TEST_METHOD(Triad_Init_SetsValues)
        {
            Vector3D::Triad triad;
            triad.Init(1, 2, 3);
            Assert::AreEqual(1, triad.getX());
            Assert::AreEqual(2, triad.getY());
            Assert::AreEqual(3, triad.getZ());
        }

        TEST_METHOD(Triad_SetX_UpdatesValue)
        {
            Vector3D::Triad triad;
            triad.Init(0, 0, 0);
            triad.setX(5);
            Assert::AreEqual(5, triad.getX());
        }

        TEST_METHOD(Triad_ToString_FormatsCorrectly)
        {
            Vector3D::Triad triad;
            triad.Init(1, 2, 3);
            std::string expected = "(1, 2, 3)";
            Assert::AreEqual(expected, triad.toString());
        }
       
       
	};
}
