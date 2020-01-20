#include <chrono>
#include <string>
#include <iostream>
//#include <filesystem>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "utils.h"
#include "Image.h"

using namespace cv;
using namespace std;
//namespace fs = std::filesystem;

int main() {
    // Base path for input and output folders
    string base_path = "C:\\Users\\Matteo\\Dropbox\\University\\11\\PC\\kernel_img_proc";
    string input_folder = base_path + "\\input\\";
    string output_folder = base_path + "\\output\\";
    string file_name = "test.bmp";
    string test = input_folder + file_name;

    // Image declaration and reading
    Mat img;
    img = imread(test, IMREAD_COLOR);

    // Creating a new Image object and storing the image in it
    Image pic = Image(file_name, img.cols, img.rows);
    storeImage(pic, img);

    // Applying blur effect
    applyKernel(pic);

    // Picture output



    // test
    int dim = 3;
    vector<vector<int>> oof(dim, vector<int> (dim, 0));
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            oof[i][j] = i;
        }
    }


    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << oof[i][j];
        }
        cout << endl;
    }


    return 0;
}
