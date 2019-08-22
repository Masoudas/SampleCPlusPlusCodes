#include "MinimaDetecor.h"
using namespace std;

void minimaDetector(const char* addressRead, const char* addressWrite) {
	Mat image = imread(addressRead, 1);

	
	int ROI[4] = { 0, 0, 512, 512 };
	image.adjustROI(0, 512, 0, 512);

	Mat gray_image1;
	cvtColor(image, gray_image1, COLOR_BGR2GRAY);

	Mat_<float> gray_image;
	gray_image1.convertTo(gray_image, CV_32FC1, 1 / 255.0);

	Mat_<float> Blurred1;
	Mat_<float> Blurred2;
	Mat_<float> DoG;

	GaussianBlur(gray_image, Blurred1, Size(7, 7), 2.2, 2.2);
	GaussianBlur(gray_image, Blurred2, Size(11, 11), 3, 3);
	
	DoG = Blurred2 - Blurred1;
	Blurred2 = DoG.clone();

	for (int row = 4; row < DoG.rows - 4; row+=1) {
		for (int column = 4; column < DoG.cols - 4; column+=1) {
			compareWithNeighborPixels(&DoG, &gray_image, row, column);
		}
	}
	

	String windowName = "Minima of DoG";
	namedWindow(windowName, 2);
	imshow(windowName, DoG + gray_image);
	waitKey(0);

	destroyWindow(windowName);
	imwrite(addressWrite, DoG + gray_image);
	
}

void compareWithNeighborPixels(Mat* image, Mat* originalImag, int row, int column) {
	//unsigned char* imageMat = image->data;
	//unsigned char* imageMat1 = originalImag->data;
	
	int stepSize = image->step;
	double currentPixel = image->at<float>(row, column); //*(imageMat + (stepSize * row) + column);

	for (int row_check = -1; row_check < 2; row_check+=1) {
		for (int column_check = -1; column_check < 2; column_check+=1) {
			if (row_check != 0 || column_check != 0) {
				if (image->at<float>(row + row_check, column + column_check) <= currentPixel) {
					return;
				}
			}
		}
	}
	

	image->at<float>(row, column) = -1;
	/*
	for (int row_check = -2; row_check < 3; row_check++) {
		for (int column_check = -2; column_check < 3; column_check++) {
			image->at<float>(row + row_check, column + column_check) = 1;
		}
	}
	*/

}

