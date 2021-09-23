#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char** argv) {
	Mat src = imread("../sample/lena512color.bmp");
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	imshow("src", src);
	Mat gray, hsv;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	cvtColor(src, hsv, COLOR_BGR2HSV);
	imshow("gray", gray);
	imshow("hsv", hsv);
	imwrite("gray.bmp", gray);
	imwrite("hsv.bmp", hsv);

	waitKey(0);
	destroyAllWindows();
	return 0;
}