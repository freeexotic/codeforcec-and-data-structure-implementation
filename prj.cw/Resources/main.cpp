
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/*
 *int main(){
    string path = "/Users/vsevolodsilaev/CLionProjects/opencvtest/Resources/testvideo.mp4";
    VideoCapture cap(path);
    Mat img;
    while (true) {
        cap.read(img);

        imshow("Video", img);
        waitKey(1);
    }
}
 */
/* int main() {
    VideoCapture cap(0);

    Mat img;

    while (true){
        cap.read(img);

        imshow("Image", img);
        waitKey(1);
    }
}
*/

  int main(){
    string path = "/Users/vsevolodsilaev/CLionProjects/opencvtest/Resources/testpet.jpg";
    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);
}

