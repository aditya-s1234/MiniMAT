//
// Created by Aditya Subramanian on 8/13/26.
//

#pragma once
#include <vector>
#include "Matrix.h"

class Application {
private:
    std::vector<Matrix> m_matrixStorage{};
    int m_input {};

public:
    Application() = default;

    void run();
    void matrixOperations();
    void create();
    void add();
    void mult();
    void scalar();
    void transpose();


};