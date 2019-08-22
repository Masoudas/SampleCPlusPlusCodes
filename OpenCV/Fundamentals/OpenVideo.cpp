#include "OpenVideo.h"
void openVideo(const char* address)
{
	VideoCapture cap;	// This the object used for capturing videos.
	cap.open(string(address));

	cv::String windowName = "Image";
	namedWindow(windowName, WINDOW_AUTOSIZE);

	Mat frame;
	while (1) {
		cap >> frame;	// The cap object has every frame stored in it. The double shift implies that pop-out one frame. Hence at some point, cap would be 
						// empty;
		if (frame.empty()) return;
		imshow(windowName, frame);
		waitKey(cap.get(CAP_PROP_XI_FRAMERATE));	// wait as long as the frame rate of the image.
	}
}


// We want to write a program where if s is pressed, we show a video frame by frame. If r is pressed, we continue.
// Approach one: Straightforward! So when g_run is -1, we continue showing frames. 
// When it is 1, we show one frame, when it is zero, we show no frame. Could have implemented the algorithm directly with a char!

void movingAroundFrames(const char* address) {
	VideoCapture g_cap;
	g_cap.open(string(address));

	int g_run = 1;
	int initiateWindow = 0;
	
	String windowName = "Window";
	namedWindow(windowName, WINDOW_AUTOSIZE);

	Mat frame;
	while (1) {
		if (g_run != 0) {
			g_cap >> frame; if (frame.empty()) break;
	
			imshow(windowName, frame);
			if (g_run == 1) g_run = 0;
		}

		char c = (char)cv::waitKey(10);

		if (c == 's') // single step
		{
			g_run = 1; cout << "Single step, run = " << g_run << endl;
		}

		if (c == 'r') // run mode
		{
			g_run = -1; cout << "Run mode, run = " << g_run << endl;
		}

		if (c == 'x') // run mode
		{
			g_run = 1; cout << "Restart mode, run = " << g_run << endl;
			g_cap.set(CAP_PROP_POS_FRAMES, 1);
		}

		if (c == 27) break; // This is the character for scape.
	}

}

// We can use a trackbar to track an object, especially a video.
VideoCapture g_cap;
void onTrackbarSlide(int pos, void*) {
	// This method is the callback method, which is called when the image is closed.
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);	// Set the current frame to pos.

}

void trackBar(const char* address) {	
	g_cap.open(string(address));
	
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);

	String windowName = "Window";
	String trackName = "Position";

	cv::namedWindow(windowName, WINDOW_AUTOSIZE);
	
	int currentFrame = 0;
	int previousFrame = 0;

	cv::createTrackbar(trackName, windowName, &currentFrame, frames, onTrackbarSlide);

	Mat frame;
	while(1) {
		if (currentFrame != previousFrame) {
			int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
			
			g_cap >> frame;
			if (frame.empty()) {
				g_cap.set(cv::CAP_PROP_POS_FRAMES, previousFrame);	// Set the current frame to pos.
				cv::setTrackbarPos(trackName, windowName, previousFrame); // We can set the position of the trackbar when want it from the program.
																		// For example suppose the video was moving automatically, we need to set the trackbar.
				g_cap >> frame;
			};
			imshow(windowName, frame);
			
			previousFrame = currentFrame;
		}
		waitKey(50);
		//g_cap >> frame; //if (frame.empty()) break;
		//int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
		
//		
		
	}

	
}