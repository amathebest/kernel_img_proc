#include <string>
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
    string file_name = "test.bmp";
    string test_in = input_folder + file_name;
    string test_out = output_folder + file_name;
    bool parallel = false;

    // Image declaration and reading
    printf("Reading the image..\n");
    Mat img;
    img = imread(test_in, IMREAD_COLOR);

    // Setting the kernel and the padding value
    float kernel_value = 1 / (float)9;
    vector<vector<float>> kernel(kernel_dim, vector<float>(kernel_dim, kernel_value));
    int padding = kernel_dim-1;

    // Creating a new Image object and storing the image in it
    Image pic = Image(file_name, img.cols, img.rows);
    storeImage(pic, img, padding);

    // Applying blur effect
    printf("Processing the image..\n");
    steady_clock::time_point time_1 = steady_clock::now();
    applyKernel(pic, kernel);
    steady_clock::time_point time_2 = steady_clock::now();
    printf("Time elapsed: %dms\n", duration_cast<milliseconds>(time_2 - time_1).count());

    // Picture output
    setPixels(pic, img);
    imwrite(test_out, img);

    return 0;
}
