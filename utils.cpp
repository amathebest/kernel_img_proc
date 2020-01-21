//
// Created by Matteo on 19/01/2020.
//
#include "utils.h"
#include "Image.h"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

// Function that takes an Image and a Mat object and sets the values for the bands inside the Image object.
void storeImage(Image &pic, Mat &img, int padding) {
    // Temporary RGB matrices with padding
    vector<vector<int>> B(img.rows + padding, vector<int> (img.cols + padding, 0));
    vector<vector<int>> G(img.rows + padding, vector<int> (img.cols + padding, 0));
    vector<vector<int>> R(img.rows + padding, vector<int> (img.cols + padding, 0));

    // Reading the 3 matrices for R, G and B and assigning the bands to the Image object
    for (int i = 0; i < img.cols; i++) {
        for (int j = 0; j < img.rows; j++) {
            Vec3b pixel = img.at<Vec3b>(i, j);
            B[i+1][j+1] = pixel.val[0];
            G[i+1][j+1] = pixel.val[1];
            R[i+1][j+1] = pixel.val[2];
        }
    }
    pic.setBands(B, G, R);
}

// Function that sets the value of the pixels of the blurred image from the values of the 3 processed bands.
void setPixels(Image &pic, cv::Mat &img) {
    for (int i = 0; i < img.cols; i++) {
        for (int j = 0; j < img.rows; j++) {
            img.at<Vec3b>(i, j)[0] = pic.getProcBand(0)[i][j];
            img.at<Vec3b>(i, j)[1] = pic.getProcBand(1)[i][j];
            img.at<Vec3b>(i, j)[2] = pic.getProcBand(2)[i][j];
        }
    }
}

// Function that takes an Image object and applies a kernel on each of its bands.
// It does so by setting the matrices for the processed bands.
void applyKernel(Image &pic, vector<vector<float>> kernel) {
    // Looping on the RGB bands
    for (int band = 0; band < 3; band++) {
        vector<vector<float>> procBand(pic.getWidth(), vector<float>(pic.getHeight(), 0)); // Support matrix for the currently processed band
        vector<vector<int>> currentBand = pic.getBand(band); // Current processed band
        // Looping through the image keeping the padding in consideration
        for (int i = 1; i < pic.getWidth()+1; i++) {
            for (int j = 1; j < pic.getHeight()+1; j++) {
                float acc = 0;
                for (int kcol = 0; kcol < kernel_dim; kcol++) {
                    for (int krow = 0; krow < kernel_dim; krow++) {
                        // Looping on kernel values and storing the accumulator value
                        acc += currentBand[i+kcol-1][j+krow-1] * kernel[kcol][krow];
                    }
                }
                procBand[i-1][j-1] = acc;
            }
        }
        pic.setProcessedBand(procBand, band);
    }
}

void applyKernel_parallel(Image &pic, vector<vector<float>> kernel) {

}