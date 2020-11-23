#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6.4/project6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c;
			int n = 10;
			int p[10] = { 1,2,3,4,5,6,7,8,-9,10 };
			c = find_min_index(p, n);
			Assert::AreEqual(c, 8);
		}
	};
}
