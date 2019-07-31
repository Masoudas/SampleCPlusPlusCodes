#include "BasicDataTypes.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;


void MatrixType() {
	Mat matrix;	// This is the matrix type, which can hold image info and whatever. Examples of initialization 

	Mat M1(2, 3, CV_8UC3, Scalar(255, 255, 255));	// This is a white image. 2*3
	Mat M2(2, 2, CV_8UC3, Scalar(0, 0, 0));		// This is a black image. 2*2
	Mat M3(2, 2, CV_8UC3, Scalar(0, 0, 100));	// This is a red image. 2*2
	Mat M4(2, 2, CV_8UC3, Scalar(100, 0, 0));	// This is a blue image. 2*2
	Mat M5(2, 2, CV_8UC1, Scalar(100));	// So this would be a grayscale image.

	Mat* ptr;	// We can define a pointer to matrix of course. There's also another type of pointer.

	Mat row = M1.rowRange(0, 1); // This is a row instance of the M1 matrix from row 0 to row 1.
	Mat column = M1.colRange(0, 1); // This is a row instance of the M1 matrix from row 0 to row 1.

	// The methods can also be called using the range class.
	Range range(0, 1);
	Mat row1 = M1.rowRange(range); // This is a row instance of the M1 matrix from row 0 to row 1.
	Mat column1 = M1.colRange(range); // This is a row instance of the M1 matrix from row 0 to row 1.

	M1 = M1.t();	// Returns the transpose of the matrix
//	M1 = M1.inv();

	// This method performs element wise multiplication on the matrix.
	M2 = (M1/50).mul(M1/50);	// Multiplication element wise.

	// This is interesting. The following method adds a new image to bottom of the current image.
	M2.push_back(M4);

	cout << M2 << endl;

	// There's the concept of the region of interest. See https://www.learnopencv.com/how-to-select-a-bounding-box-roi-in-opencv-cpp-python/
	Size2i ROIsize;
	//ROIsize.height = 2;
	//ROIsize.width = 3;

	Point2i point;// (1, 1);
	M2.locateROI(ROIsize, point);

	

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

	//Ptr<Mat> ptr = &image;	// Well apparently this is a pointer form that can be used for all types inside the library.
							// The difference I suppose is that Ptr class holds the number of references to a similair object.
							// Hence I guess It can be used for effective memory management
							// The methods of the pointer class with respect to a template can be overriden so that
							// an operation can be done while destruction for example.

	/// To see the content of the class, see https://docs.opencv.org/3.4/d0/de7/structcv_1_1Ptr.html.
	
	

	// Now the image is shown, because the object is released.
}

void Point2D() {
	// Defines points.
	Point2f p1{1.2,1.5};	// Both values are in float;
	Point2f p2{ 1.5, 1.5 };
	p1 = p1 + p2;
	
	p1.cross(p2);	// Not the actual cross vector result.
	
	double normOfVector = norm(p1);

	Point2f p3;
	Point2l p4;

	// We can also define 3D points
	Point3f p5;
}


void Size(const char* address) {
	// A class which can be used to define the size of an image, or hold the image size for that matter.
	// Although it should be mentioned that the image class on it's own right provides these information.
	Mat image = imread(address);
	
	Size2d imSize;
	imSize = image.size();

	if (!imSize.empty()) {
		cout << "Image area is: " << imSize.area() << endl;
		cout << "Image area is: " << imSize.aspectRatio() << endl;
		cout << "Image width is: " << imSize.width << endl;
		cout << "Image height is: " << imSize.height << endl;
	}	
}

void Rectangle() {
	Rect2i rect(1, 1, 1, 1);


	//// Draw a rotated rectangle on the image.
	Mat image(100, 100, CV_8UC3, Scalar(255, 255, 255);
	
	Point2f p1{ 1.2,1.5 };	// Both values are in float;
	Point2f p2{ 1.5, 1.5 };
	
	RotatedRect rectRotated(p1, p2, 45);	// Ok rotates this rectangle. Then it will return the points corresponding to this rotated points.

	Point2f points[4];
	rectRotated.points(points);	// Hence we have the four points.

	for (int i = 0; i < 4; i++) {
		// Draw a line on the vertices.
	}
	
}
