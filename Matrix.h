//
// Created by Aditya Subramanian on 8/12/26.
//

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::istream& operator>> (std::istream& in, std::vector<double>& arr) {

}

class Matrix {
private:
    //matrices organized within m_matrix vector

    std::vector<std::vector<double>> m_matrix {};

public:



    Matrix ()
        :Matrix(int {0}, int {0})
    {

    }

    Matrix (int rows, int cols) {
        setMatrix(rows, cols);
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




};
