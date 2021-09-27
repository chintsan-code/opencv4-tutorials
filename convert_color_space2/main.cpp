#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char** argv) {
	Mat src = imread("../sample/greenback.png");
	if (src.empty()) {
		cout << "could not load image..." << endl;
		return -1;
	}
	imshow("src", src);
	Mat hsv, mask;
	cvtColor(src, hsv, COLOR_BGR2HSV);
	imshow("hsv", hsv);
	inRange(hsv, Scalar(35, 43, 36), Scalar(77, 255, 255), mask);
	imshow("mask", mask);

	Mat redback = Mat::zeros(src.size(), src.type());
	redback = Scalar(40, 40, 200);
	bitwise_not(mask, mask);
	imshow("mask2", mask);
	src.copyTo(redback, mask);
	imshow("dst", redback);

	waitKey(0);
	destroyAllWindows();
	return 0;
}