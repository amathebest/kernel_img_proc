//
// Created by Matteo on 19/01/2020.
//
#include "Image.h"
#include "opencv2/core/core.hpp"

#ifndef KERNEL_IMG_PROC_UTILS_H
#define KERNEL_IMG_PROC_UTILS_H

const int kernel_dim = 3;
const float kernel[kernel_dim][kernel_dim] = {1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9};

void storeImage(Image pic, cv::Mat img);

void applyKernel(Image pic);

#endif //KERNEL_IMG_PROC_UTILS_H

