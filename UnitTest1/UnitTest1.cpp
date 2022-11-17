#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.1.IT/PR7.1.IT.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** T = new int* [3];
			for (int i = 0; i < 3; i++) {

				T[i] = new int[3];
			}
			T[0][0] = 1;
			T[0][1] = 2;
			T[0][2] = -3;

			T[1][0] = 4;
			T[1][1] = 5;
			T[1][2] = -6;

			T[2][0] = 7;
			T[2][1] = -8;
			T[2][2] = 9;
			int t = Suma(T, 3, 3);
			Assert::AreEqual(t, -9);
		}
	};
}
