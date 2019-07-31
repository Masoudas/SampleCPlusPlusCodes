// See also https://docs.opencv.org/2.4/modules/imgproc/doc/filtering.html
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int display_caption(const char* caption);
int display_dst(int delay, const char* addressToWrite);


Mat src; Mat dst;
char window_name[] = "Filter Demo 1";


/*
	An issue that arises when filtering a signal is how we want to treat the borders. Here's how:
 Various border types, image boundaries are denoted with '|'  (these are left and right borders)

 * BORDER_REPLICATE:     aaaaaa|abcdefgh|hhhhhhh
 * BORDER_REFLECT:       fedcba|abcdefgh|hgfedcb
 * BORDER_REFLECT_101:   gfedcb|abcdefgh|gfedcba
 * BORDER_WRAP:          cdefgh|abcdefgh|abcdefg
 * BORDER_CONSTANT:      iiiiii|abcdefgh|iiiiiii  with some specified 'i'
 */

void GaussianFilter(const char* address, const char* addressToWrite) {
	/// Load the source image
	src = imread(address);
	resizeWindow(window_name, src.rows/3, src.cols / 3);

	//if (display_caption("Original Image") != 0) { return; }

	dst = src.clone();
	//if (display_dst(0) != 0) { return; }

	/// Applying Homogeneous blur
	//if (display_caption("Homogeneous Blur") != 0) { return ; }

	//for (int i = 1; i < 31; i = i + 2)
	//{
	//	blur(src, dst, Size(i, i), Point(-1, -1));
	//	if (display_dst(0) != 0) { return; }
	//}

	///// Applying Gaussian blur
	//if (display_caption("Gaussian Blur") != 0) { return; }

	//for (int i = 1; i < 31; i = i + 2)
	//{
	//	GaussianBlur(src, dst, Size(i, i), 0, 0);
	//	if (display_dst(0) != 0) { return; }
	//}

	///// Applying Median blur
	//if (display_caption("Median Blur") != 0) { return; }

	//for (int i = 1; i < 31; i = i + 2)
	//{
	//	medianBlur(src, dst, i);
	//	if (display_dst(0) != 0) { return; }
	//}

	///// Applying Bilateral Filter
	//if (display_caption("Bilateral Blur") != 0) { return; }

	//for (int i = 1; i < 31; i = i + 2)
	//{
	//	bilateralFilter(src, dst, i, i * 2, i / 2);
	//	if (display_dst(0) != 0) { return; }
	//}

	/// Applying Two Gaussians, and then showing the difference.
	if (display_caption("Difference Gaussian") != 0) { return; }

	Mat dst1; 
	Mat dst2;
	
	cvtColor(src, dst, COLOR_BGR2GRAY);
	
	GaussianBlur(dst, dst1, Size(5, 5), 1, 1);
	GaussianBlur(dst, dst2, Size(1, 1), 1, 1);

	dst = 100 * (dst1 - dst2);
	
	if (display_dst(0, addressToWrite) != 0) { return; }
	cout << dst;
	/// Wait until user press a key
	display_caption("End: Press a key!");

	waitKey(0);
	return;
}


int display_caption(const char* caption)
{
	namedWindow(window_name, WINDOW_NORMAL);
	resizeWindow(window_name, dst.rows / 3, dst.cols / 3);
	dst = Mat::zeros(src.size(), src.type());
	putText(
		dst, caption, Point(src.cols / 4, src.rows / 2),
		HersheyFonts::FONT_HERSHEY_SIMPLEX, 6, Scalar(255, 255, 255)); // Put a text string in the image.	
	
	imshow(window_name, dst);
	int c = waitKey(0);
	destroyWindow(window_name);
	if (c >= 0) { return -1; }
	return 0;
}

int display_dst(int delay, const char* addressToWrite)
{
	namedWindow(window_name, WINDOW_NORMAL);
	resizeWindow(window_name, dst.rows / 3, dst.cols / 3);
	imshow(window_name, dst);
	imwrite(addressToWrite, dst);
	int c = waitKey(delay);
	destroyWindow(window_name);
	if (c >= 0) { return -1; }
	return 0;
}

