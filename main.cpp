#include <iostream>
#include "Matrix.h"

int main () {
    Matrix x{2,3};
    Matrix y{3,2};

    Matrix z (x.multiplyMatrix(y));
    z.printMatrix();
    return 0;
}