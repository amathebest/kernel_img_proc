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
    int padding = kernel_dim-1;
    // Creating a new Image object and storing the image in it
    Image pic = Image(file_name, img.cols, img.rows);
    storeImage(pic, img, padding);
    cout << pic.getWidth() << endl;
    cout << pic.getBand(0).size() << endl;

    // Applying blur effect
    float kernel_value = 1 / (float)9;
    vector<vector<float>> kernel(kernel_dim, vector<float>(kernel_dim, kernel_value));

    applyKernel(pic, kernel);

    // Picture output


    return 0;
}
