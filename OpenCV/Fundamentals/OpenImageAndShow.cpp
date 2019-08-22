// See https://docs.opencv.org/2.4/doc/tutorials/core/mat_the_basic_image_container/mat_the_basic_image_container.html.

//#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>	// This header contains the imread, matrix and other stuff.
#include <iostream>
#include <string> 

using namespace cv;
using namespace std;

void OpenAndShow(const char* path, int windowSize, int* ROI)
{
	// Unit test
	//const char* path = "c:\\Something.jpg";
	//int ROI[4] = { 0, 0, 2000, 3000 };	// The region of interest that we want to see
	//OpenAndShow(path, 2, ROI);

	//// Read the image file
	Mat image = imread(path);
	//Mat image = imread(path, IMREAD_GRAYSCALE); Load image as gray scale
	Mat copyImage(image);	// The copy constructor.
	// The above form of constructor shallow copies the class. For a deepcopy, we need to use two methods:  clone() and copyTo() 
	Mat deepImageCopy = image.clone();
	Mat anotherDeepCopy; 
	image.copyTo(anotherDeepCopy);


	//image.adjustROI(); To adjust the region of interest.
	Mat ImageWithRegionOfInterest(copyImage, Rect(*ROI, *(ROI + 1), *(ROI + 2), *(ROI + 3)));

	if (ImageWithRegionOfInterest.empty()) // Check for failure
	{
		cout << "Could not open or find the image" << endl;
		system("pause"); //wait for any key press
	}

	String windowName = "My HelloWorld Window"; //Name of the window

	namedWindow(windowName, windowSize); // Create a window

	imshow(windowName, ImageWithRegionOfInterest); // Show our image inside the created window.

	waitKey(0); // Wait for any keystroke in the window

	destroyWindow(windowName); //destroy the created window
}


void openingAnManipulatinInFloatPoint() {
	https://stackoverflow.com/questions/22688117/writing-a-float-image-in-opencv-with-pixel-values-bigger-than-1
	https://stackoverflow.com/questions/15130162/how-to-access-pixel-values-of-cv-32f-cv-64f-mat
}



void ShowEmptyFigure(int windowSize)
{
	// Unit test
	// ShowEmptyFigure(2);

	//// Read the image file
	//// We start from black and add color. The format is BGR.
	//// The number of channels and types and stuff are defined according to this formula:
	// CV_[The number of bits per item][Signed or Unsigned][Type Prefix]C[The channel number]

	Mat M1(2, 3, CV_8UC3, Scalar(255, 255, 255));	// This is a white image.
	Mat M2(2, 2, CV_8UC3, Scalar(0, 0, 0));		// This is a black image.
	Mat M3(2, 2, CV_8UC3, Scalar(0, 0, 100));	// This is a red image.
	Mat M4(2, 2, CV_8UC3, Scalar(100, 0, 0));	// This is a blue image.
	Mat M5(2, 2, CV_8UC1, Scalar(100));	// This is a blue image.	// So this would be a grayscale image.

	Mat* arr[5] = { &M1, &M2, &M3, &M4, &M5};

	String windowName = "Second Window"; //Name of the window
	for (int i = 0; i < 5; i++) {
		windowName.append(to_string(i)); // converting to int.
		cout << **(arr + i) << endl;
		namedWindow(windowName, windowSize); // Create a window

		imshow(windowName, **(arr+i)); // Show our image inside the created window.

		waitKey(0); // Wait for any keystroke in the window

		destroyWindow(windowName); //destroy the created window
	}
	

	// Accessing the actual image data.
	
	unsigned char* ptr = M1.data;	// So data style depends on the layout that we defined for the image. For example, here the image is 2D with
									// three channel. Hence, each row contains three elements for each pixel. hence, we have a 2*3 number of columns and
									// two rows.
	cout << "nRows " << M1.rows << endl;
	cout << "nColumns " << M1.cols << endl;
	cout << "nChannels " << M1.channels() << endl;
	cout << "imageStep " << M1.step << endl;	// This is the total number of columns in each row. i.e., M1.cols * M1.channels().

	for (int j = 0; j < M1.rows; j++) {
		for (int i = 0; i < M1.step; i+=M1.channels()) {
			cout << "Blue is " << (int) *(ptr + j * M1.step + i) << endl;
			cout << "Green is " << (int) *(ptr + j * M1.step + i + 1) << endl;
			cout << "Red is " << (int) *(ptr + j * M1.step + i + 2) << endl;

			// Messing with the colors!
			*(ptr + j * M1.step + i) = 30 * (j + 1) * i;
			*(ptr + j * M1.step + i + 1) = 30 * (j + 1) * (i + 1);
			*(ptr + j * M1.step + i + 2) = 30 * (j + 1) * (i + 2);

		}
	}

	namedWindow(windowName, windowSize); // Create a window
	imshow(windowName, M1); // Show our image inside the created window.
	waitKey(0); // Wait for any keystroke in the window
	destroyWindow(windowName); //destroy the created window
}


void OtherInitializers(void) {
	// There are other forms of initializations here too.
	int sz[3] = { 2,2,2 };	
	Mat M1(3, sz, CV_8UC(1), Scalar::all(0)); // Using a pointer to a 3D vector, we can initialize a 3D matrix. I don't know the use,
											// because we can't display this matrix, and none of the basic methods seem to work for this too.

	Mat M2 = Mat::eye(4, 4, CV_64F);
	
	cout << "M2 = " << endl << " " << M2 << endl << endl;

	Mat M3 = Mat::ones(2, 2, CV_32F);
	cout << "M3 = " << endl << " " << M3 << endl << endl;

	Mat M4 = Mat::zeros(3, 3, CV_8UC1);
	M4 = M4 - 1;	// Simple scaling and addition is accepted.
	M4 = M4 * 1/256;
	M4 = M4 * 524;
	cout << "M4 = " << endl << " " << M4 << endl << endl;

	Point2f point[4];	// This a famous data type, used for storing a 2d point in float.
	point[0].x = 10.2;
	point[0].y = 11.2;

}