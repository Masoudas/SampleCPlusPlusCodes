#include <iostream>

void getVersion() {
	// The version is associated with microsoft. It is different from VC++14 and stuff. But VS 2019 is equivalent to VC++14.2
	// https://stackoverflow.com/questions/31885337/what-compiler-is-in-visual-studio-2015
	std::cout << _MSC_VER;
	std::cout << _MSC_FULL_VER;
}
