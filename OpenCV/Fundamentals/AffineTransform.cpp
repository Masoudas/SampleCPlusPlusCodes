// See https://docs.opencv.org/3.1.0/d4/d61/tutorial_warp_affine.html. Note that the affine transforms are defined as 2*3 matrices 
// rather than 3*3 matrices.
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"	

using namespace cv;
void ApplyAffineTransform(const char* address) {
	Mat image, imageAfterWarp, imageAfterWarpRotate;
	/// Loading the image
	image = imread(address);

	imageAfterWarp = Mat::zeros(image.rows, image.cols, image.type());	// Another fancy way of initializing the warp_dst matrix to zero.
														// In this matrix we keep the matrix of image after applying the
	imageAfterWarp.copyTo(imageAfterWarpRotate);



	// Now we define two sets of three points and calculate their affine transform.
	Mat warp_mat(2, 3, CV_32FC1); // First notice that we define the affine transform using the normal matrix.
													// Scalar::all starts the entire matrix at zero.
	
	Point2f srcTri[3];
	Point2f dstTri[3];

	srcTri[0] = Point2f(0, 0);
	srcTri[1] = Point2f(image.cols - 1.f, 0);
	srcTri[2] = Point2f(0, image.rows - 1.f);

	dstTri[0] = Point2f(image.cols * 0.0f, image.rows * 0.33f);
	dstTri[1] = Point2f(image.cols * 0.85f, image.rows * 0.25f);
	dstTri[2] = Point2f(image.cols * 0.15f, image.rows * 0.7f);

	warp_mat = getAffineTransform(srcTri, dstTri);	// Now we find the affine transform between the points.
	warpAffine(image, imageAfterWarp, warp_mat, imageAfterWarp.size());
	///////////////////////////////////

	//// Now we rotate the image.
	Mat rot_mat(2, 3, CV_32FC1, Scalar::all(0));

	Point center = Point(imageAfterWarp.cols / 2, imageAfterWarp.rows / 2);
	double angle = -10;
	double scale = 1;	// The scale should be 1, and not zero! otherwise we get no image if it's zero.

	rot_mat = getRotationMatrix2D(center, angle, scale);
	warpAffine(imageAfterWarp, imageAfterWarpRotate, rot_mat, imageAfterWarpRotate.size());
	//////////////////////////////////
	
	
	namedWindow("OriginalImage", 2);
	namedWindow("WarpedImage", 2);
	namedWindow("RotatedWarpedImage", 2);

	imshow("OriginalImage", image);
	imshow("WarpedImage", imageAfterWarp);
	imshow("RotatedWarpedImage", imageAfterWarpRotate);

	waitKey(0);

	destroyAllWindows();

}