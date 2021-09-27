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
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1, LINE_8, 0);
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1, LINE_8, 0);
	imshow("m1", m1);
	imshow("m2", m2);

	Mat dst;
	bitwise_and(m1, m2, dst);
	imshow("and", dst);
	bitwise_not(src, dst);
	//dst = ~src;
	imshow("not", dst);
	bitwise_or(m1, m2, dst);
	imshow("or", dst);
	bitwise_xor(m1, m2, dst);
	imshow("xor", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}