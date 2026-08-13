#include <iostream>
#include "Matrix.h"

int main () {
    Matrix x{3,2};
    Matrix y{3,2};

    Matrix z{x.addMatrix(y)};
    z.printMatrix();

    z.subtractMatrix(x).printMatrix();

    return 0;
}