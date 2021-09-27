#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src, dst, m;
int lightness = 50;
void onChange(int, void*) {
	dst = src + Scalar(lightness, lightness, lightness);
	imshow("lightness", dst);
}

int main(int argc, const char** argv) {
	src = imread("../sample/lena512color.bmp");
	if (src.empty()) {
		cout << "could not load image..." << endl;
		return -1;
	}
	imshow("src", src);
	namedWindow("lightness", WINDOW_AUTOSIZE);
	int maxValue = 100;
	createTrackbar("Value bar:", "lightness", &lightness, maxValue, onChange);
	onChange(50, 0);

	waitKey(0);
	destroyAllWindows();
	return 0;
}