#include <iostream>
#include "Matrix.h"
#include "Application.h"



int main () {

    // Application app;
    // app.run();

    Matrix m {{2,1,-1}, {-3,-1,2}, {-2,1,2}};
    Vector x {3};
    m.gaussianElimination(x).printMatrix();





    return 0;
}