//
// Created by Matteo on 19/01/2020.
//
#include <string>
#include <vector>

#ifndef KERNEL_IMG_PROC_IMAGE_H
#define KERNEL_IMG_PROC_IMAGE_H

using namespace std;

class Image {
public:
    Image(string name, int width, int height) {
        this->name = name;
        this->width = width;
        this->height = height;
    }

    string getName() {
        return this->name;
    }

    int getWidth() {
        return this->width;
    }

    int getHeight() {
        return this->height;
    }

    vector<vector<int>> getBand(int type) {
        if (type == 0) {
            return this->B;
        } else if (type == 1) {
            return this->G;
        } else {
            return this->R;
        }
    }

    void setBands(vector<vector<int>> B, vector<vector<int>> G, vector<vector<int>> R, bool proc) {
        if (proc == true) {
            this->procB = B;
            this->procG = G;
            this->procR = R;
        } else {
            this->B = B;
            this->G = G;
            this->R = R;
        }
    }

private:
    string name;
    int width;
    int height;
    vector<vector<int>> B;
    vector<vector<int>> G;
    vector<vector<int>> R;
    vector<vector<int>> procB;
    vector<vector<int>> procG;
    vector<vector<int>> procR;
};

#endif //KERNEL_IMG_PROC_IMAGE_H