#include "pch.h"
#include "CppUnitTest.h"
#include "../Rectangle.h"
#include "../Rectangle.cpp"
#include "../utilities.h"
#include "../utilities.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(DefaultInit)
        {
            Rectangle rect;
            rect.Init();
            Assert::AreEqual(0.0, rect.getX());
            Assert::AreEqual(0.0, rect.getY());
            Assert::AreEqual(1.0, rect.getWidth());
            Assert::AreEqual(1.0, rect.getHeight());
            Assert::AreEqual(0.0, rect.getAngle());
        }

        TEST_METHOD(SetWidth)
        {
            Rectangle rect;
            Assert::IsTrue(rect.setWidth(10.0));
            Assert::AreEqual(10.0, rect.getWidth());
            Assert::IsFalse(rect.setWidth(-5.0));
            Assert::AreEqual(0.0, rect.getWidth());
        }

        TEST_METHOD(SetHeight)
        {
            Rectangle rect;
            Assert::IsTrue(rect.setHeight(5.0));
            Assert::AreEqual(5.0, rect.getHeight());
            Assert::IsFalse(rect.setHeight(-3.0));
            Assert::AreEqual(0.0, rect.getHeight());
        }
    };
}