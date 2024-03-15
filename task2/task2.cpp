//Задание 2
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    Mat image = imread("C:/Users/James-Bond/Downloads/cat.jpg");

    if (image.empty())
    {
        cout << "Ошибка при загрузке изображения!" << endl;
        return -1;
    }

    namedWindow("RGB", WINDOW_NORMAL);
    imshow("RGB", image);

    Mat hsvImage;
    cvtColor(image, hsvImage, COLOR_BGR2HSV);
    namedWindow("HSV", WINDOW_NORMAL);
    imshow("HSV", hsvImage);

    Mat labImage;
    cvtColor(image, labImage, COLOR_BGR2Lab);
    namedWindow("Lab", WINDOW_NORMAL);
    imshow("Lab", labImage);

    Mat yuvImage;
    cvtColor(image, yuvImage, COLOR_BGR2YUV);
    namedWindow("YUV", WINDOW_NORMAL);
    imshow("YUV", yuvImage);

    Mat xyzImage;
    cvtColor(image, xyzImage, COLOR_BGR2XYZ);
    namedWindow("XYZ", WINDOW_NORMAL);
    imshow("XYZ", xyzImage);

    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    namedWindow("GRAY", WINDOW_NORMAL);
    imshow("GRAY", grayImage);

    waitKey(0);

    return 0;
}
