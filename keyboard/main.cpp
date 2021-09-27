#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char** argv) {
	Mat src = imread("../sample/lena512color.bmp");
	if (src.empty()) {
		cout << "could not load image..." << endl;
		return -1;
	}
	imshow("src", src);
	Mat dst = src.clone();
	while (true) {
		int c = waitKey(10);
		if (c == 27) {
			// ESC
			break;
		}
		if (c == 49) {
			// num1
			cout << "you press key #1" << endl;
			cvtColor(src, dst, COLOR_BGR2GRAY);
		}
		if (c == 50) {
			// num2
			cout << "you press key #2" << endl;
			cvtColor(src, dst, COLOR_BGR2HSV);
		}
		if (c == 51) {
			// num3
			cout << "you press key #3" << endl;
			add(src, Scalar(50, 50, 50), dst);
		}			
		imshow("dst", dst);
	}

	destroyAllWindows();
	return 0;
}