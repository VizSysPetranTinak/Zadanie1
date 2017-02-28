#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;
int counter;

int main() {

	VideoCapture vcap(0);
	if (!vcap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	int frame_width = vcap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
	VideoWriter video("out.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height), true);

	while (counter<100) {

		Mat frame;
		stringstream file;
		vcap >> frame;
		file << "C:/Users/Boi/Documents/Obrazky/image" << counter << ".bmp";
		counter++;
		imwrite(file.str(), frame);
		char c = (char)waitKey(33);
		if (c == 27) break;
	}
	int i = 0;

	while (counter != i) {
		Mat image;
		string fajl;
		std::string s = std::to_string(i);
		fajl = "C:/Users/Boi/Documents/Obrazky/image" + s + ".bmp";
		image = imread(fajl, CV_LOAD_IMAGE_UNCHANGED);
		video.write(image);
		imshow("Frame", image);
		i++;
	}

	return 0;
}