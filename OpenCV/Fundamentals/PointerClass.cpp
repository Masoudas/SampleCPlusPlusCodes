#include "PointerClass.h"
#include <iostream>
#include <opencv2/highgui.hpp>

using namespace cv;


void basics()
{
	Matx33d mat1;
	mat1.zeros();

	Ptr<Matx33d> ptr(&mat1);	// So this a smart pointer to the Mat type.

	std::cout << mat1(2, 2) << std::endl;

	std::cout << (*ptr)(0, 0) << std::endl;
	
//	ptr.release(); // This method just decreases the reference counter, and does not delete the object.

}

// So we can override the definition of the release function for a particular type of pointer, which can be useful.
// This is a famous example
template<> void Ptr<FILE>::release() {
	fclose(this->get());
}


/// Pointer type. Read below.
template<> void Ptr<Mat>::release() {
	String name = "Released Object";
	namedWindow(name, 2);
	imshow(name, *this->get());
	waitKey(0);
	destroyWindow(name);
}

void PointerType(const char* address) {
	Mat image = imread(address);

	Ptr<Mat> ptr = &image;	// Well apparently this is a pointer form that can be used for all types inside the library.
							// The difference I suppose is that Ptr class holds the number of references to a similair object.
							// Hence I guess It can be used for effective memory management
							// The methods of the pointer class with respect to a template can be overriden so that
							// an operation can be done while destruction for example.
	ptr.release();
	ptr.reset();
	/// To see the content of the class, see https://docs.opencv.org/3.4/d0/de7/structcv_1_1Ptr.html.



	// Now the image is shown, because the object is released.
	Mat image1;
}
