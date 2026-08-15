//
// Created by Aditya Subramanian on 8/13/26.
//

#pragma once
#include <vector>
#include "Matrix.h"

class Vector {
private:
    std::vector<double> m_vector{};


public:
    Vector() {
        setVector(0);
    }

    Vector (int row) {
        setVector(row);
    }

    Vector (std::vector<double> list)
        :m_vector(list)
    {
    }

    void setVector(int row) {
        for (std::ptrdiff_t i{}; i < row; ++i) {
            double temp{};
            std::cout << "Enter a value: ";
            std::cin >> temp;
            m_vector.push_back(temp);
        }
    }

    void printVector() const;

    //this is so that matrix methods can modify vectors as if it was an augmented matrix
    friend class Matrix;
};