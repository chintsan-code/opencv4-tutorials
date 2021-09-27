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
	// split
	vector<Mat> channels;
	split(src, channels);
	imshow("B", channels[0]);  //单通道图像
	imshow("G", channels[1]);
	imshow("R", channels[2]);
	// merge
	Mat dst;
	channels[0] = 0;
	channels[1] = 0;
	merge(channels, dst);
	imshow("dst", dst); // 三通道，但是B、G通道都为0	
	//mixChannels
	int from_to[] = { 0,2,1,1,2,0 }; // 第1个通道交换至第3个通道，第2个通道不交换，第3个通道交换至第1个通道
	mixChannels(&src, 1, &dst, 1, from_to, 3);
	imshow("mixchannels", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}