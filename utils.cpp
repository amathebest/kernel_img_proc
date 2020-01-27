//
// Created by Matteo on 19/01/2020.
//
#include <iostream>
#include "utils.h"
#include "Image.h"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

// Function that sets the value of the pixels of the blurred image from the values of the 3 processed bands.
void setPixels(Image &pic, cv::Mat &img) {
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            img.at<Vec3b>(i, j)[0] = pic.getProcBand(0)[i+1][j+1];
            img.at<Vec3b>(i, j)[1] = pic.getProcBand(1)[i+1][j+1];
            img.at<Vec3b>(i, j)[2] = pic.getProcBand(2)[i+1][j+1];
        }
    }
}

// Function that takes an Image object and applies a kernel on each of its bands.
// This process uses a 3x3 kernel matrix composed by 1/9 as kernel values.
// This applies a soft blur to the image.
void applyKernel(Image &pic, vector<vector<float>> kernel) {
    int filter_size = 1; // This is set to 1 in order to loop from -filter_size to +filter_size
    // Looping on the RGB bands
    for (int band = 0; band < 3; band++) {
        vector<vector<int>> currentBand = pic.getBand(band); // Current processed band
        vector<vector<float>> procBand(pic.getHeight()+2, vector<float>(pic.getWidth()+2, 0)); // Support matrix for the currently processed band
        // Looping through the image keeping the padding in consideration
        for (int i = 1; i < pic.getHeight()+1; i++) {
            for (int j = 1; j < pic.getWidth()+1; j++) {
                float acc = 0;
                for (int krow = -filter_size; krow < filter_size+1; krow++) {
                    for (int kcol = -filter_size; kcol < filter_size + 1; kcol++) {
                        // Looping on kernel values and storing the accumulator value
                        acc += currentBand[i+krow][j+kcol] * kernel[krow+1][kcol+1];
                    }
                }
                procBand[i][j] = acc;
            }
        }
        pic.setProcessedBand(procBand, band);
    }
}
/*      int w = 5;
        int h = 3;
        vector<vector<int>> in(h+2, vector<int>(w+2, 0));
        vector<vector<float>> out(h+2, vector<float>(w+2, 0));
        cout << "In: " << endl;
        for (int i = 0; i < h+2; i++) {
            for (int j = 0; j < w+2; j++) {
                if (i > 0 && i < h+1 && j > 0 && j < w+1) {
                    in[i][j] = i;
                }
                cout << in[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 1; i < h+1; i++) {
            for (int j = 1; j < w+1; j++) {
                float acc = 0;
                for (int krow = -filter_size; krow < filter_size+1; krow++) {
                    for (int kcol = -filter_size; kcol < filter_size + 1; kcol++) {
                        // Looping on kernel values and storing the accumulator value
                        cout << i + krow << j + kcol << "; " << i << j << "; " << krow << kcol << "; ";
                        acc += in[i + krow][j + kcol] * kernel[krow + 1][kcol + 1];
                    }
                }
                cout << endl;
                out[i][j] = acc;
            }
        }

        cout << "Out: " << endl;
        for (int i = 0; i < h+2; i++) {
            for (int j = 0; j < w+2; j++) {
                cout << out[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Kernel: " << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << kernel[i][j] << " ";
            }
            cout << endl;
        }
 */