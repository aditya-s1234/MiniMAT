//
// Created by Aditya Subramanian on 8/13/26.
//

#pragma once
#include <vector>
#include "Matrix.h"
#include "Vector.h"

class Application {
private:
    std::vector<Matrix> m_matrixStorage{};
    std::vector<Vector> m_vectorStorage{};
    int m_input {};

public:
    Application() = default;

    void run();
    void matrixOperations();
    void create();
    void createVect();
    void add();
    void mult();
    void scalar();
    void transpose();
    void gaussian();
    void solve();
    void determinant();


};