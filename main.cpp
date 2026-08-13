#include <iostream>
#include "Matrix.h"

int main () {
    Matrix x{{1,2,3}, {4,5,6}};

    x.transposeMatrix().printMatrix();


    return 0;
}