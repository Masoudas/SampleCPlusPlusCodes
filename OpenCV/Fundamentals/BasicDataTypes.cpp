// All the following types are define in https://docs.opencv.org/2.4/modules/core/doc/basic_structures.html 

#include "BasicDataTypes.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;


// In a more general sense, we have point classes, size classes, vector classes.
// Point classes are 2d, 3d and 4d (scalars). Their members are named x, y, z, except for scalar which has a val parameter.
// Vector classes are accessed through indexing. 
// Size classes are on the other hand rectangle like objects, so they have width and height. Rect class is kind of in the middle,
// because it has both x,y and width and height.

// Note that for the vector and matrix data types, we also have fixed sizes (Matx and Vec2x, or Vec3x and so on). For matrices, it's just Matx.
// The last important fundamental type is the complex numbers.

// We also have helper classes, which do several functionalities:
// TermCriteria is short for termination criteria, which help determine the end criteria of many algorithms.

// There's also two classes, called InputArray and OutputArray. The former is always constant. The presence of these two classes
// imply that we can use any of the basic types as the IO of the algorithm.

// Note that types that end in underscore are apparently the templates. For example, Point_.

void VectorType() {
	cv::Vec<uchar, 4> vec{1,2,3,4};	// The first paramter of the template indicate type, second indicate number of elements, which can be {2,3,4,6}
	cout << vec[0];	// So vectors are accessed by their index, in contrast to Points which are accessed by the dot operator.

	cv::Vec<Point2f, 4> matVec;	// The first paramter of the template indicate type, second indicate number of elements, which can be {2,3,4,6}
	//Vec<Mat, 4> matVec;	// This will return an exception, because Mat does not have a predetermined size.
	

	// There are many typedefs for constant size vectors. They are essentially the same as fixed size matrices.
	Vec2b vec2;	

}

void ScalarType() {
	Scalar scalar(0, 1, 255, 0);	// Scalar is basically a 4D data type.
	cout << scalar[0];	
}

void complex() {
	Complexd complexVal(1.0, 1.0);
	cout << "Imaginary part" << complexVal.im;
	cout << "Real part" << complexVal.re;
}


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

	
	// To read a particular pixel of the image, one can use the at method.
	Vec3b vec;
	vec = M1.at<Vec3b>(1, 1);	// Define the template before the function call, remember?

	// For the grayscale image, we could do this:
	uchar pixel = M5.at<uchar>(1, 1);
	

	cv::Matx<int, 2, 2> mat;	// The Matx is a small size matrix, whose dimensions we must know at compile time! Used for storing small size transforms.
	mat = mat.randn(1, 1);	// Instantiate the matrix with normal distribution.

	cout << "Another way of acessing the matrix element" << mat(0, 0) << endl; // But works only for small scale matrices.

	// Reshaping the matrix
	cv::Matx<int, 4, 1> reshapedMat = mat.reshape<4, 1>();

	// Casting.
	cv::Matx<float, 4, 1> castedToFloat = reshapedMat;

	// Getting a submatrix from the same matrix.
	cv::Matx<float, 2, 1> extractSubmatrix = reshapedMat.get_minor<2,1>(0,0); // Getting a submatrix from element (0,0) of size 2*1.
	
	Matx33d mat33;
	mat33 = mat33.randn(1.0, 1.0);

	cout << mat33 << endl;
	mat33 = mat33.inv();
	cout << mat33 << endl;

	Matx31d mat31;
	mat31 = mat31.randn(1, 1);

	cout << mat33 * mat31 << endl;
	

}


void Point2D() {
	// Defines points.
	Point2d p1{ 1.2, 1.5 };	// Both values are in float;
	Point2d p2{ 1.5, 1.5 };
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
	Rect2i rect1(2, 2, 2, 2);

	rect1 = rect1 & rect;	// Returns the intersection of two rectangles.
	// rect1 = rect1 | rect;	// Returns the minimum area rectangle.


	//// Draw a rotated rectangle on the image.
	Mat image(100, 100, CV_8UC3, Scalar(255, 255, 255));
	
	Point2f p1{ 50.2, 50.5 };	// Center of rectangle
	Point2f p2{ 10.5, 10.5 };	// Width and height of rectangle
	
	RotatedRect rectRotated(p1, p2, 45);	// Ok rotates this rectangle. Then it will return the points corresponding to this rotated points.
	
	Point2f points[4];
	rectRotated.points(points);	// Hence we have the four points.

	for (int i = 0; i < 4; i++) {
		// Draw a line on the vertices.
		line(image, points[i], points[(i+1) % 4], Scalar(0, 0, 255), 1);
	}

	string window = "Yo";
	namedWindow(window, 2);
	
	imshow(window, image);

	waitKey(0);
}

void terminationCriteria() {
	// Using this class, we can tell the algorithm when to stop, on number of iterations, epsilon value, or both(?).
	TermCriteria termCriteria1(TermCriteria::COUNT, 100, 0.001);		// So in this variation, we say that we want a condition on number of iterations, 100.
	TermCriteria termCriteria2(TermCriteria::MAX_ITER, 100, 0.001);		// This is equivalent to the previous.
	TermCriteria termCriteria3(TermCriteria::EPS, 100, 0.001);		// This one says condition is on epsilon.
}

void inputArrayOutputArray() {
	InputArray arrIn{};
	OutputArray arrOut{};
	const InputOutputArray arInOut{};

	/*
	The following assignment however does not make sense, because arrOut is not the base class of array types.
	Rect2i const sc;
	arrOut = sc;
	*/

	// Sometimes when an array wants an array as input/output, but it's optional, we may give noArr()
	// as the input function.
	noArray();
}


