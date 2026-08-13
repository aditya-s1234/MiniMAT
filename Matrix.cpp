//
// Created by Aditya Subramanian on 8/12/26.
//

#include "Matrix.h"

// matrix printing and arithmetic operations here

void Matrix::printMatrix() const{
    for (const auto& i : m_matrix) {
        for (const auto& j : i) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}

const Matrix Matrix::addMatrix(const Matrix& matrix2) const{
    std::vector<std::vector<double>> matrixSum {};
    if (m_matrix.size() == matrix2.m_matrix.size()) {
        if (m_matrix[0].size() == matrix2.m_matrix[0].size()) {
            for (std::ptrdiff_t i{}; i < std::ssize(m_matrix); ++i) {
                std::vector<double> tempVect{};
                for (std::ptrdiff_t j{}; j < std::ssize(m_matrix[i]); ++j) {
                    tempVect.push_back(m_matrix[i][j] + matrix2.m_matrix[i][j]);
                }
                matrixSum.push_back(tempVect);
            }
        }
    }
    return Matrix{matrixSum};
}

const Matrix Matrix::subtractMatrix(const Matrix& matrix2) const{
    std::vector<std::vector<double>> matrixSum {};
    if (m_matrix.size() == matrix2.m_matrix.size()) {
        if (m_matrix[0].size() == matrix2.m_matrix[0].size()) {
            for (std::ptrdiff_t i{}; i < std::ssize(m_matrix); ++i) {
                std::vector<double> tempVect{};
                for (std::ptrdiff_t j{}; j < std::ssize(m_matrix[i]); ++j) {
                    tempVect.push_back(m_matrix[i][j] - matrix2.m_matrix[i][j]);
                }
                matrixSum.push_back(tempVect);
            }
        }
    }
    return Matrix{matrixSum};
}

