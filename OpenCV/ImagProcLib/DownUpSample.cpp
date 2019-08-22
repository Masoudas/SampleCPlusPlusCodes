#include "DownUpSample.h"

void resample(const char* address)
{
	Mat img1, img2;

	namedWindow("Example1", cv::WINDOW_AUTOSIZE);
	namedWindow("Example2", cv::WINDOW_AUTOSIZE);

	img1 = imread(address);
	imshow("Example1", img1);
	
	pyrDown(img1, img2);
	imshow("Example2", img2);
	
	waitKey(0);
}
