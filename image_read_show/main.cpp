#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("../sample/lena512color.bmp",IMREAD_ANYDEPTH);
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	namedWindow("input", WINDOW_FREERATIO);
	imshow("input", src);

	waitKey(0);
	destroyAllWindows();
	return 0;
}