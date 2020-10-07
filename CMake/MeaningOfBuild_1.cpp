/*
* What do we mean by building a C++ project? I Think three things:
* 
* 1- Creating an executable: 
			By this, we imply an .exe, or .bin for linux, which will run THE ONLY main method
*	of our C++ program.
* 
* 2- Creating a dynamically linked library:
*			Or dll. By this we mean the sort of library that will be linkked to our code during runtime.
* 
* 3- Creating a statically linked library:
*			Or a .lib library. This is used for statically linking a library to our code (which would allow the compiler
*	to perform some optimization with the other library and our code.
* 
* Note that a build has a target platform, and that which ever one of these is built, it is aimed for a particular
* platform.
* 
* The object of CMake is to make this process easy and convinent for us.