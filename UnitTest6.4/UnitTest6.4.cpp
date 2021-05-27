#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Massive<int>A[5] = { 1, 2, 3, 4, 5 };
			A[5].sort("Down");
			Assert::AreEqual(1, 1);
		}
	};
}
