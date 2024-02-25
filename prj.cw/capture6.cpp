//
// Created by Всеволод Силаев on 22.02.2024.
//
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

Mat imgGray, imgBlur, imgCanny, imgDil;

void getContur(Mat imgDil , Mat img){
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    drawContours(img, contours, -1, Scalar(255,0,255), 2);
    imshow("Conturs", img);
}

int main(){
    string path = "/Users/vsevolodsilaev/CLionProjects/opencvtest/Resources/testpet.jpg";
    Mat img = imread(path);
// The preprocessor of the image //
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray,imgBlur, Size(5,5), 3, 1);
    Canny(imgBlur, imgCanny, 90 ,140);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(imgCanny, imgDil, kernel);
/////////////////////
    imshow("Image", imgDil);
    getContur(imgDil, img);
    waitKey(0);
}
