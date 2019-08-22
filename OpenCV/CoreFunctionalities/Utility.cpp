#include "Utility.h"

void mathOperations()
{
	atan2(1, 1);	// arctan of a function.
	fastAtan2(1, 1);
	auto ceilVal = ceil(1.1);
	floorl(1e-25);


}

void memoryRelated()
{
	// Dynamic allocation and deallocation of of memory.
	Mat* ptr = nullptr;
	Allocator<Mat> alloc;
	alloc.allocate(4 * sizeof(Mat), ptr);
	alloc.deallocate(ptr, 4 * sizeof(Mat));


}

void raisingErrorRelated()
{
	double x = 0;
	//CV_Assert(x != 0);	// We assert that the condition is satisfied and if not, we raise an error.
	//CV_DbgAssert(x != 0);	// Only asserted in the debug mode.

	
}
