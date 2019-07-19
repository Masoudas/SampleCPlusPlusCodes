#include "pch.h"
#include "CppUnitTest.h"
#include "../SampleCPlusPlusCodes/Classes/Fundamentals.h" // The double points to go back to the root folder.
// To create a test project, create a new project in the solution, search for test in the types of new projects.
// 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsForTheProject
{
	TEST_CLASS(TestsForMyClass) // TestsForTheProject is the name that appears on the test explorer window.
	{
	public:
		TEST_METHOD(TestStringIsCorrect)	// Each method shall appear under the class name.
		{
			std::string str = "This string is shallow copied";
			MyClass myClass{};
			Assert::AreEqual(str, myClass.str);	// So the assert method asserts that the result of the results are equal.
			// At this point, first build this project, and then go to the
			// go to test menu and find the test explorer window. The tests shall appear and performed.
		}

		TEST_METHOD(TestStringIsNotIncorrect)	
		{
			std::string str = "This string is deep copied";
			MyClass myClass{};
			Assert::AreNotEqual(str, myClass.str);	
		}

	};
}
