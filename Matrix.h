//
// Created by Aditya Subramanian on 8/12/26.
//

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>



class Matrix {
private:
    //matrices organized within m_matrix vector

    std::vector<std::vector<double>> m_matrix {};

public:



    Matrix ()
        :Matrix(0, 0)
    {

    }
    //construct with rows and cols
    Matrix (int rows, int cols) {
        setMatrix(rows, cols);
    }
    //construct with 2d array
    Matrix (const std::vector<std::vector<double>>& vect)
        :m_matrix (vect)
    {
    }

    //construct with Matrix
    Matrix (const Matrix& matrix)
        :m_matrix(matrix.m_matrix)
    {
    }

    void setMatrix(int numRows, int numCols) {
        for (int i{}; i < numRows; ++i) {
            std::cout << "Enter row " << i << ": ";

            //get the entire line, feeds into stringstream to convert inputs into doubles and pushes into row
            std::string line;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            std::vector<double> row;
            double val;
            while (ss >> val) {
                row.push_back(val);
            }
            m_matrix.push_back(row);

        }
    }



    void printMatrix() const;
    Matrix addMatrix(const Matrix&) const;
    Matrix subtractMatrix(const Matrix& matrix2) const;
    Matrix multiplyMatrix(const Matrix& matrix2) const;
};
