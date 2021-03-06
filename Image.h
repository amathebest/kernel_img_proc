//
// Created by Matteo on 19/01/2020.
//
#include <string>
#include <vector>

#ifndef KERNEL_IMG_PROC_IMAGE_H
#define KERNEL_IMG_PROC_IMAGE_H

using namespace std;

class Image {
private:
    int width;
    int height;
    vector<vector<int>> B;
    vector<vector<int>> G;
    vector<vector<int>> R;
    vector<vector<float>> procB;
    vector<vector<float>> procG;
    vector<vector<float>> procR;

public:
    Image(int width, int height, vector<vector<int>> B, vector<vector<int>> G, vector<vector<int>> R) {
        this->width = width;
        this->height = height;
        this->B = B;
        this->G = G;
        this->R = R;
    }

    // Getters
    int getWidth() {
        return this->width;
    }

    int getHeight() {
        return this->height;
    }

    const vector<vector<int>> &getBand(int type) const {
        if (type == 0) {
            return this->B;
        } else if (type == 1) {
            return this->G;
        } else {
            return this->R;
        }
    }

    const vector<vector<float>> &getProcBand(int type) const {
        if (type == 0) {
            return this->procB;
        } else if (type == 1) {
            return this->procG;
        } else {
            return this->procR;
        }
    }

    // Setters
    void setProcessedBand(vector<vector<float>> const &procBand, int whichBand) {
        if (whichBand == 0) {
            this->procB = procBand;
        } else if (whichBand == 1) {
            this->procG = procBand;
        } else {
            this->procR = procBand;
        }
    }
};

#endif //KERNEL_IMG_PROC_IMAGE_H
