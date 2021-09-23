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
	int w = src.cols;
	int h = src.rows;
	int dims = src.channels();
	/* 使用数组下标方式访问像素
	for (int row = 0; row < h; row++)
	{
		for (int  col = 0; col < w; col++)
		{
			if (dims == 1)
			{
				// 单通道
				int pv = src.at<uchar>(row, col);    // get
				src.at<uchar>(row, col) = 255 - pv;  // set
			}
			else if (dims == 3)
			{
				// 三通道
				Vec3b bgr = src.at<Vec3b>(row, col);
				src.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				src.at<Vec3b>(row, col)[1] = 255 - bgr[1];
				src.at<Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}
	*/
	// 使用指针的方式访问像素,速度更快
	for (int row = 0; row < h; row++)
	{
		uchar* cur = src.ptr<uchar>(row);
		for (int col = 0; col < w; col++)
		{
			if (dims == 1)
			{
				// 单通道
				int pv = *cur;
				*cur++ = 255 - *cur;
			}
			else if (dims == 3)
			{
				// 三通道
				*cur++ = 255 - *cur;
				*cur++ = 255 - *cur;
				*cur++ = 255 - *cur;
			}
		}
	}
	imshow("src2", src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}