#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

void DrawLine(const char* address, int lineType) {
	Mat image = imread(address);

	Point start{0, 0};
	Point end{ 300, 300 };
	Scalar color{ 0, 0, 200 };
	int thickness = 5;


	line(image, start, end, color, thickness, lineType, 0); // Last argument is shift – Number of fractional bits in the point coordinates

	namedWindow("LineInImage", 2);
	imshow("LineInImage", image);
	waitKey(0);
	destroyAllWindows();
}


void PutText(const char* address, int lineType) {
	Mat image = imread(address);

	String text = "\'Sup?";
	Point origin{ 150, 150 };
	Scalar color{ 0, 0, 200 };
	int thickness = 5;
	double fontScale = 5;

	putText(
		image, text, origin, HersheyFonts::FONT_HERSHEY_SIMPLEX, fontScale, color, thickness, lineType, false); // Last element is bottomLeftOrigin.

	namedWindow("LineInImage", 2);
	imshow("LineInImage", image);
	waitKey(0);
	destroyAllWindows();
}