#include "opencv2/opencv.hpp"
#include <sstream>
#include <iostream>


using namespace cv;
using namespace std;

Mat frame, img;
int counter;

int main(int, char**)
{
	
	while (counter>50)
	{
		stringstream file;

		VideoCapture cap(0); // open the default camera
		if (!cap.isOpened())  // check if we succeeded
			return -1;

		Mat edges;
		namedWindow("edges", 1);

		Mat frame;
		cap >> frame; // get a new frame from camera

		//if (frame.empty()) break;
		file << "C:/Users/Boi/Documents/Obrazky/image" << counter << ".bmp";
		counter++;
		imwrite(file.str(), frame);

		char key = waitKey(10);
		if (key == 27)
		{
			break;
		}


	}


}

/*
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	VideoCapture vcap(0);
	if (!vcap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	int frame_width = vcap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
	VideoWriter video("out.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height), true);

	for (;;) {

		Mat frame;
		vcap >> frame;
		video.write(frame);
		imshow("Frame", frame);
		char c = (char)waitKey(33);
		if (c == 27) break;
	}
	return 0;
}
*/