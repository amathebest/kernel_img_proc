//
// Created by Matteo on 21/01/2020.
//

#include <iostream>

/*
Test prints
cout << i << j << " - " << kcol << krow << " : " << currentBand[i+kcol-1][j+krow-1] << " " << kernel[kcol][krow] << endl;


// test

int dim = 5;
Image testPic = Image("test", dim, dim);
vector<vector<int>> B(dim+2, vector<int> (dim+2, 0));
vector<vector<int>> G(dim+2, vector<int> (dim+2, 0));
vector<vector<int>> R(dim+2, vector<int> (dim+2, 0));
for (int band = 0; band < 3; band++) {
    for (int i = 1; i < dim+1; i++) {
        for (int j = 1; j < dim+1; j++) {
            if (band == 0) {
                B[i][j] = i;
            } else if (band == 1) {
                G[i][j] = i;
            } else {
                R[i][j] = i;
            }
        }
    }
}
testPic.setBands(R, G, B);

printf("\nNon-processed band:\n");
for (int i = 0; i < dim+2; i++) {
    for (int j = 0; j < dim+2; j++) {
        cout << testPic.getBand(0)[i][j] << " ";
    }
    cout << endl;
}
cout << endl;

applyKernel(testPic, kernel);

printf("\nNon-processed band:\n");
for (int i = 1; i < dim+1; i++) {
    for (int j = 1; j < dim+1; j++) {
        cout << testPic.getBand(0)[i][j] << " ";
    }
    cout << endl;
}
printf("Processed band:\n");
for (int i = 1; i < dim+1; i++) {
    for (int j = 0; j < dim+1; j++) {
        cout << testPic.getProcBand(0)[i][j] << " ";
    }
    cout << endl;
}

*/