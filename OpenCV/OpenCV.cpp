#include <iostream>
#include "Fundamentals/OpenImageAndShow.h"
#include "Fundamentals/ChangeToGrayScale.h"
#include "Fundamentals/AffineTransform.h"
#include "Fundamentals/Filtering.h"
#include "CoreFunctionalities/DrawAndAddText.h"
#include "Fundamentals/BasicDataTypes.h"
#include "DoGDetector/MinimaDetecor.h"
#include "Fundamentals/OpenVideo.h"
#include "ImagProcLib/DownUpSample.h"
#include "Fundamentals/PointerClass.h"
#include "CoreFunctionalities/Utility.h"

//typedef unsigned char  CV_8UC3; 

int main(int argc, char** argv)
{
	const char* addressRead = "C:\\Users\\sharbaf\\Downloads\\BeadImages\\Beads_test2_C1.tif";
	const char* addressWrite = "C:\\Users\\sharbaf\\Downloads\\BeadImages\\Beads_test2_C11.tif";
	/*	
	Mat im1 = imread(addressRead);
	Mat im2 = imread(addressWrite);

	

	String name = "RegisteredDiff";
	namedWindow(name, WND_PROP_AUTOSIZE);

	Matx23d transform(0.95341252638496, -9.03727525502E-4, 97, -1.4291238459E-4, 0.999597739689547, -8.550752829763212);
	Mat warp = (Mat)transform;

	Mat im3 = im2.clone();
	
	warpAffine(im2, im3, warp, im3.size());
	
	Mat im5;
	double min, max;
	minMaxLoc(im2, &min, &max);

	im1.convertTo(im5, CV_8UC3, (uchar)max, 0);
	
	Mat im4 = im2.clone();
	absdiff(im1, im3, im4);

	imshow(name, im4);
	waitKey(0);*/
	minimaDetector(addressRead, addressWrite);
	//ApplyAffineTransform(addressRead);
	//resample(addressRead);
	//MatrixType();

	//basics();
	//PointerType(addressRead);
//	const char* path = "C:\\Users\\sharbaf\\Downloads\\video.mp4"; \
//	trackBar(path);
}