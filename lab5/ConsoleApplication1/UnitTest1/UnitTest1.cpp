#include "pch.h"
#include "CppUnitTest.h"
#include "D:\c++ lab\lab5\ConsoleApplication1\ConsoleApplication1\ConsoleApplication1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(CalAndPrint)
	{
	public:

		TEST_METHOD(calculate1)
		{
			int n = 3;
			double x = -3;
			double Expected = -2;
			double Actual = y(n, x);
			Assert::AreEqual(Expected, Actual);
		}
	public:

		TEST_METHOD(calculate2)
		{
			int n = 4; double x = -11;
			double Expected = -10;
			double Actual = y(n, x);
			Assert::AreEqual(Expected, Actual);
		}
	public:

		TEST_METHOD(calculate3)
		{
			int n = 5;
			double x = 0;
			double Expected = -1000;
			double Actual = y(n, x);
			Assert::AreEqual(Expected, Actual);
		}
	};
	TEST_CLASS(cheD)
	{
	public:
		TEST_METHOD(Data1)
		{
			int n = 3; double x = -1, b = 1, h = 0.1;
			try
			{
				checkData(n, x, b, h);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(Data2)
		{
			int n = -1; double x = 0.4, b = 11, h = 0.7;
			try
			{
				checkData(n, x, b, h);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}
