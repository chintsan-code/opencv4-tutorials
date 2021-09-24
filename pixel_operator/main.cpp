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
	Mat dst1 = src + Scalar(50, 50, 50);
	imshow("add", dst1);
	Mat dst2 = src - Scalar(50, 50, 50);
	imshow("sub", dst2);
	Mat dst3;
	multiply(src, Scalar(2, 2, 2), dst3);
	imshow("mul", dst3);
	Mat dst4 = src / Scalar(2, 2, 2);
	imshow("div", dst4);

	//另一种方式实现加法
	Mat dst5 = Mat::zeros(src.size(), src.type());
	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			Vec3b p1 = src.at<Vec3b>(row, col);  // BGR
			dst5.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + 50);
			dst5.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + 50);
			dst5.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + 50);
		}
	}
	imshow("add2", dst5);

	waitKey(0);
	destroyAllWindows();
	return 0;
}