//
// Created by Matteo on 19/01/2020.
//
#include "Image.h"

#ifndef KERNEL_IMG_PROC_UTILS_H
#define KERNEL_IMG_PROC_UTILS_H

float kernel[3][3] = {1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9};

void storeImage(Image pic, cv::Mat img);

void applyKernel(Image pic);

#endif //KERNEL_IMG_PROC_UTILS_H

