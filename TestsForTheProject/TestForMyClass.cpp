#include "pch.h"
#include "CppUnitTest.h"
#include "../SampleCPlusPlusCodes/Classes/Fundamentals.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsForTheProject 
{
	TEST_CLASS(Test2ForMyClass)
	{
	public:
		TEST_METHOD(CheckVal) {
			int val = 10;
			MyClass myClass{};
			Assert::AreEqual(val, myClass.val);	// Casting from integer to float is done with no problem.

		}

	};
}