//
// Created by Matteo on 19/01/2020.
//
#include "Image.h"
#include "opencv2/core/core.hpp"

#ifndef KERNEL_IMG_PROC_UTILS_H
#define KERNEL_IMG_PROC_UTILS_H

const int kernel_dim = 3;

void setPixels(Image &pic, cv::Mat &img);

void applyKernel(Image &pic, vector<vector<float>> kernel);

#endif //KERNEL_IMG_PROC_UTILS_H

