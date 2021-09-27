#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void onLightnessChange(int pos, void* userdata) {
	/*
	Mat src = *((Mat*)userdata);
	Mat dst = src + Scalar(pos, pos, pos);
	imshow("lightness_contrast", dst);
	*/

	Mat src = *((Mat*)userdata);
	Mat dst = Mat::zeros(src.size(), src.type());
	Mat m = Mat::zeros(src.size(), src.type());
	m = Scalar(pos, pos, pos);
	addWeighted(src, 1.0, m, 0, pos, dst);  //dst=src+pos
	imshow("lightness_contrast", dst);
}

void onContrastChange(int pos, void* userdata) {
	Mat src = *((Mat*)userdata);
	Mat dst = Mat::zeros(src.size(), src.type());
	Mat m = Mat::zeros(src.size(), src.type());
	double contrast = pos / 100.0;  //pos:0-200；constast:0-2.0
	m = Scalar(pos, pos, pos);
	addWeighted(src, contrast, m, 0, 0, dst);  //dst=src*contrast
	imshow("lightness_contrast", dst);
}

int main(int argc, const char** argv) {
	Mat src = imread("../sample/lena512color.bmp");
	if (src.empty()) {
		cout << "could not load image..." << endl;
		return -1;
	}
	imshow("src", src);
	namedWindow("lightness_contrast", WINDOW_AUTOSIZE);
	int lightness_value = 50;
	int maxValue = 100;
	int contrast_value = 100;
	createTrackbar("Lightness Value:", "lightness_contrast", &lightness_value, maxValue, onLightnessChange, &src);
	createTrackbar("Contrast Value:", "lightness_contrast", &contrast_value, 200, onContrastChange, &src);
	onLightnessChange(lightness_value, &src);
	onContrastChange(contrast_value, &src);

	waitKey(0);
	destroyAllWindows();
	return 0;
}