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
	Mat m1, m2;
	m1 = src.clone(); // 克隆
	m1.copyTo(m2);  //拷贝
	imshow("src", src);
	imshow("m1", m1);
	imshow("m2", m1);

	// 创建空白对象
	//Mat m3 = Mat::zeros(Size(512, 512), CV_8UC1);
	Mat m3 = Mat::ones(Size(512, 512), CV_8UC3);
	cout << "Width: " << m3.cols << endl
		<< "Height: " << m3.rows << endl
		<< "Channels: " << m3.channels() << endl;
	//cout << m3 << endl;
	m3 = 127; // 注意：这样只会将第一个通道赋值为127
	//cout << m3 << endl;
	m3 = Scalar(0, 0, 255); //这样赋值三个通道
	cout << m3 << endl;
	imshow("m3", m3);  //m3也是图像
	Mat m4 = m3;  // 赋值
	Mat m5 = m3.clone();
	m4 = Scalar(255, 0, 0);  // 改变m4，m3也会改变
	m5 = Scalar(0, 255, 0);  // 改变m5，m3不会改变
	imshow("m3-2", m3);
	imshow("m4", m4);
	imshow("m5", m5);


	waitKey(0);
	destroyAllWindows();
	return 0;
}