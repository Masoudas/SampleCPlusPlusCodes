#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;

void changeToGrayScaleAndSave(const char* address, const char* addressToSave) {
//	const char* address = "C:\\Users\\sharbaf\\Downloads\\Beads_test2.tif";
//	const char* addressToSave = "C:\\Users\\sharbaf\\Downloads\\Beads_test2.tif";
//	changeToGrayScaleAndSave(address, addressToSave);
	Mat im = imread(address, 1);
	
	cout << "Step in image one: " << im.step << endl;

	if (im.empty()) {
		cout << "Could not open or find the image" << endl;
		system("pause"); //wait for any key press
	}

	Mat gray_image;
	cvtColor(im, gray_image, COLOR_BGR2GRAY);

	// As we can see, the step size for this image has decreased three fold.
	cout << "Step in image two: " << gray_image.step;

	String windowName = "GrayImage";

	namedWindow(windowName, 2);
	imshow(windowName, gray_image);

	waitKey(0);
	destroyWindow(windowName);

	imwrite(addressToSave, gray_image);
}
