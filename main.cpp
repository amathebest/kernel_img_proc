#include <string>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "utils.h"
#include "Image.h"

using namespace cv;
using namespace std;
using namespace chrono;

int main() {
    // Base path for input and output folders
    string base_path = "C:\\Users\\Matteo\\Dropbox\\University\\11\\PC\\kernel_img_proc";
    string input_folder = base_path + "\\input\\";
    string output_folder = base_path + "\\output\\";
    string file_name = "pic2.bmp";
    string file_in = input_folder + file_name;
    string file_out = output_folder + file_name;

    // Image declaration and reading
    printf("Reading the image..\n");
    Mat img;
    img = imread(file_in, IMREAD_COLOR);

    // Setting the kernel and the padding value
    int padding = kernel_dim-1;
    float kernel_value = 1 / (float)9;
    vector<vector<float>> kernel(kernel_dim, vector<float>(kernel_dim, kernel_value));

    // Temporary RGB matrices with padding
    vector<vector<int>> B(img.rows + padding, vector<int> (img.cols + padding, 0));
    vector<vector<int>> G(img.rows + padding, vector<int> (img.cols + padding, 0));
    vector<vector<int>> R(img.rows + padding, vector<int> (img.cols + padding, 0));

    // Reading the 3 matrices for B, G and R
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            Vec3b pixel = img.at<Vec3b>(i, j);
            B[i+1][j+1] = pixel.val[0];
            G[i+1][j+1] = pixel.val[1];
            R[i+1][j+1] = pixel.val[2];
        }
    }

    // Creating a new Image object and storing the three bands in it
    Image* pic = new Image(img.cols, img.rows, B, G, R);

    // Applying blur effect
    printf("Processing the image..\n");
    steady_clock::time_point time_1 = steady_clock::now();

    applyKernel(*pic, kernel);

    steady_clock::time_point time_2 = steady_clock::now();
    printf("Time elapsed: %Id[ns]\n", duration_cast<nanoseconds>(time_2 - time_1).count());

    // Picture output
    setPixels(*pic, img);
    imwrite(file_out, img);

    return 0;
}
