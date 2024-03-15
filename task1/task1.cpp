//Задание 1
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    string imagePath = "C:/Users/James-Bond/Downloads/image.jpg";

    Mat src, dst, color_dst, gray, img;
    if (!(src = imread(imagePath, 1)).data)
    {
        cout << "Ошибка при загрузке изображения!" << endl;
        return -1;
    }

    namedWindow("картинка", 1);
    imshow("картинка", src);

    Canny(src, dst, 50, 200, 3);
    cvtColor(dst, color_dst, COLOR_GRAY2BGR);
    vector<Vec4i> lines;
    HoughLinesP(dst, lines, 1, CV_PI / 180, 80, 30, 10);
    for (size_t i = 0; i < lines.size(); i++)
    {
        line(color_dst, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 3, 8);
    }

    namedWindow("линии", 1);
    imshow("линии", color_dst);

    if (!(img = imread(imagePath, 1)).data)
    {
        cout << "Ошибка при загрузке изображения!" << endl;
        return -1;
    }

    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray, Size(9, 9), 2, 2);
    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 2, gray.rows / 4, 200, 100);

    for (size_t i = 0; i < circles.size(); i++)
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        circle(img, center, radius, Scalar(255, 0, 0), 3, 8, 0);
    }

    namedWindow("круги", 1);
    imshow("круги", img);

    waitKey(0);
    return 0;
}
