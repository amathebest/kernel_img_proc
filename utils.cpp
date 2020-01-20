//
// Created by Matteo on 19/01/2020.
//

#include "Image.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

void storeImage(Image pic, Mat img) {
    // Temporary RGB matrices
    vector<vector<int>> B(img.rows, vector<int> (img.cols, 0));
    vector<vector<int>> G(img.rows, vector<int> (img.cols, 0));
    vector<vector<int>> R(img.rows, vector<int> (img.cols, 0));

    // Reading the 3 matrices for R, G and B and assigning the bands to the Image object
    for (int i = 0; i < img.cols; i++) {
        for (int j = 0; j < img.rows; j++) {
            Vec3b pixel = img.at<Vec3b>(i, j);
            B[i][j] = pixel.val[0];
            G[i][j] = pixel.val[1];
            R[i][j] = pixel.val[2];
        }
    }
    pic.setBands(B, G, R, false);
}

void applyKernel(Image pic) {
    // Looping through the image
    for (int i = 0; i < pic.getWidth(); i++) {
        for (int j = 0; j < pic.getHeight(); j++) {

        }
    }
}