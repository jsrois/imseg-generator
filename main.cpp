#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>

static const double alphaValue = 0.3;

using namespace std;
using namespace cv;


void print_usage() {
    cout << "Usage:\timseg-generator <image-file> <points-file> <ouput-file>\n";
}

vector<Point> getVector(const string &pointsFile) {
    vector<Point> points;
    ifstream inputStream(pointsFile);
    while (!inputStream.eof())
    {
        float x,y;
        inputStream >> x >> y;
        points.emplace_back(x,y);
    }
    return points;
}

Mat getMaskedImage(const string &imageFile, const vector<Point> &points) {
    Mat image = imread(imageFile);
    Mat originalImage = image.clone(); 
    fillPoly(image, vector<vector<Point>>{points}, Scalar (255, 0, 0) );
    auto alpha = alphaValue;
    auto tmp =  ( 1-alpha)*originalImage + alpha*image;
    return Mat(tmp);
}

void generateMaskedImage(string imageFile, string pointsFile, string outputFileName) {
    vector<Point> points = getVector(pointsFile);
    Mat result = getMaskedImage(imageFile, points);
    imwrite(outputFileName, result);
}

int main(int argc, char * argv[]) {
    if (argc < 4) {
        print_usage();
        return 1;
    }
    string imageFile = argv[1];
    string pointsFile = argv[2];
    string outputFileName = argv[3];
    generateMaskedImage(imageFile, pointsFile, outputFileName);
    return 0;
}