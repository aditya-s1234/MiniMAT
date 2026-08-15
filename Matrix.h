
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <initializer_list>
#include "Vector.h"

class Vector;
class Matrix {
private:
    //matrices organized within m_matrix vector

    std::vector<std::vector<double>> m_matrix {};

public:



    Matrix ()
        :Matrix(0, 0)
    {

    }
    //construct with rows and cols (i have to remove this)
    Matrix (int rows, int cols) {
        setMatrix(rows, cols);
    }

    //constructs using initializer list format now
    Matrix(std::initializer_list<std::initializer_list<double>> listConstruct) {
        for (std::initializer_list row : listConstruct) {
            std::vector<double> tempVect {};
            for (double x : row) {
                tempVect.push_back(x);
            }
            m_matrix.push_back(tempVect);
        }
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
            //REMEMBER******** need to change this into a kind of resizing function instead of only being called for constructor.******
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


    //member funcs
    void printMatrix() const;
    Matrix addMatrix(const Matrix&) const;
    Matrix subtractMatrix(const Matrix& matrix2) const;
    Matrix multiplyMatrix(const Matrix& matrix2) const;
    Matrix transposeMatrix() const;
    Matrix multiplyScalar(double scalar) const;
    void swapRows(int row1, int row2, Vector& vect);
    void reduceRow(int row1, int row2, Vector& vect, int pos);
    Matrix gaussianElimination(Vector& vect) const;
    Vector solveMatrix(Vector& vect) const;
};
