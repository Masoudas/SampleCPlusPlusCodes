#ifndef __OPEN_VIDEO__
#define __OPEN_VIDEO__
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void openVideo(const char* address);
void movingAroundFrames(const char* address);
void trackBar(const char* address);
#endif // !__OPEN_VIDEO__
