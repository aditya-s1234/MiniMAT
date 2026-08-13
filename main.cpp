#include <iostream>
#include "Matrix.h"




int main () {
    std::vector<Matrix> matrixStorage{};

    std::cout << "Welcome to MiniMAT, a lightweight linear algebra engine that can do matrix operations and solve linear equations. \n";
    std::cout << "Please select one of the options below, or enter '-1' to quit: \n";
    int input{};

    do {
        std::cout << "[1] Create and store a matrix \n"
                     "[2] Matrix addition/subtraction \n"
                     "[3] Matrix multiplication \n"
                     "[4] Scalar multiplication \n"
                     "[5] Transpose matrix \n";
        std::cin >> input;



    } while (input != -1);

    std::cout << "Application closing...";



    return 0;
}