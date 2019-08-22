#ifndef __MINIMA_DETECTOR__
#define __MINIMA_DETECTOR__

#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;

void minimaDetector(const char* addressRead, const char* addressWrite);
void compareWithNeighborPixels(Mat* image, Mat* image1, int row, int column);

#endif // !__MINIMA_DETECTOR__