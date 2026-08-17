#include <iostream>
#include "Matrix.h"
#include "Application.h"


int main () {

    Matrix m {{2, 1}, {1,1}};
    m.inverseMatrix().printMatrix();

    // Application app;
    // app.run();


    return 0;
}