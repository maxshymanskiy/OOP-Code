#include "pch.h"
#include "CppUnitTest.h"
#include "../Combination.cpp"
#include "../Combination.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestDefaultConstructor)
        {
            Combination c;
            Assert::AreEqual(0, c.GetFirst());
            Assert::AreEqual(0, c.GetSecond());
        }

    
	};
}
