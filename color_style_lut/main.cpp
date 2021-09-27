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
	int colormap[] = {
		COLORMAP_AUTUMN,
		COLORMAP_BONE,
		COLORMAP_JET,
		COLORMAP_WINTER,
		COLORMAP_RAINBOW,
		COLORMAP_OCEAN,
		COLORMAP_SUMMER ,
		COLORMAP_SPRING,
		COLORMAP_COOL,
		COLORMAP_HSV ,
		COLORMAP_PINK ,
		COLORMAP_HOT ,
		COLORMAP_PARULA,
		COLORMAP_MAGMA ,
		COLORMAP_INFERNO,
		COLORMAP_PLASMA ,
		COLORMAP_VIRIDIS ,
		COLORMAP_CIVIDIS ,
		COLORMAP_TWILIGHT ,
		COLORMAP_TWILIGHT_SHIFTED
	};
	Mat dst;
	int index = 0;
	while (true) {
		int c = waitKey(1000);
		if (c==27) {
			break;
		}
		applyColorMap(src, dst, colormap[index % 19]);
		imshow("dst", dst);
		index++; 
	}
	
	destroyAllWindows();
	return 0;
}