

#include "Matrix.h"
#include "Vector.h"
// matrix printing and arithmetic operations here

//SELF NOTE: REMEMBER TO ADD ERROR CHECKING TO EVERYTHING

void Matrix::printMatrix() const{
    for (const auto& i : m_matrix) {
        for (const auto& j : i) {
            if (std::abs(j) < 1e-9) {
                std::cout << 0 << " ";
                continue;
            }
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}

Matrix Matrix::addMatrix(const Matrix& matrix2) const{
    std::vector<std::vector<double>> matrixSum {};
    if (m_matrix.size() != matrix2.m_matrix.size() || m_matrix[0].size() != matrix2.m_matrix[0].size()) {
        throw std::invalid_argument("Matrix dimensions must match for addition. \n");
    }
    for (std::ptrdiff_t i{}; i < std::ssize(m_matrix); ++i) {
        std::vector<double> tempVect{};
        for (std::ptrdiff_t j{}; j < std::ssize(m_matrix[i]); ++j) {
            tempVect.push_back(m_matrix[i][j] + matrix2.m_matrix[i][j]);
        }
        matrixSum.push_back(tempVect);
    }
    return Matrix{matrixSum};
}

Matrix Matrix::subtractMatrix(const Matrix& matrix2) const{
    std::vector<std::vector<double>> matrixSum {};
    if (m_matrix.size() != matrix2.m_matrix.size() || m_matrix[0].size() != matrix2.m_matrix[0].size()) {
        throw std::invalid_argument("Matrix dimensions must match for subtraction. \n");
    }

    for (std::ptrdiff_t i{}; i < std::ssize(m_matrix); ++i) {
        std::vector<double> tempVect{};
        for (std::ptrdiff_t j{}; j < std::ssize(m_matrix[i]); ++j) {
            tempVect.push_back(m_matrix[i][j] - matrix2.m_matrix[i][j]);
        }
        matrixSum.push_back(tempVect);
    }

    return Matrix{matrixSum};
}

Matrix Matrix::multiplyMatrix(const Matrix& matrix2) const {
    std::vector<std::vector<double>> newMatrix{};
    if (m_matrix[0].size() != matrix2.m_matrix.size()) {
        throw std::invalid_argument("Cols in first matrix must match rows in second for multiplication. \n");
    }
    for (std::ptrdiff_t i{}; i < std::ssize(m_matrix); ++i) {
        std::vector<double> tempVect{};
        for (std::ptrdiff_t j{}; j < std::ssize(matrix2.m_matrix[0]); ++j) {
            double sums{};
            for (std::ptrdiff_t k{}; k < std::ssize(m_matrix[0]); ++k)
                sums+=(m_matrix[i][k] * matrix2.m_matrix[k][j]);
            tempVect.push_back(sums);
        }
        newMatrix.push_back(tempVect);

    }
    return newMatrix;
}

Matrix Matrix::transposeMatrix() const {
    std::vector<std::vector<double>> newMatrix{};
    for (std::ptrdiff_t j{}; j < std::ssize(m_matrix[0]); ++j) {
        std::vector<double> tempVect{};
        for (std::ptrdiff_t i{}; i < std::ssize(m_matrix); ++i) {
            tempVect.push_back(m_matrix[i][j]);
        }
        newMatrix.push_back(tempVect);
    }
    return newMatrix;
}

Matrix Matrix::multiplyScalar(double scalar) const {
    std::vector<std::vector<double>> newMatrix{};
    for (std::ptrdiff_t i{}; i < std::ssize(m_matrix); ++i) {
        std::vector<double> tempVect{};
        for (std::ptrdiff_t j{}; j < std::ssize(m_matrix[0]); ++j) {
            tempVect.push_back(m_matrix[i][j] * scalar);
        }
        newMatrix.push_back(tempVect);
    }
    return newMatrix;
}


//for below functions, might be better to create separate vector functions and call both
//instead of giving Matrix access to private Vector members

void Matrix::swapRows(int row1, int row2, Vector& vect) {
    std::swap(m_matrix[row1], m_matrix[row2]);
    //my own augument implementation here
    std::swap(vect.m_vector[row1], vect.m_vector[row2]);
}
void Matrix::reduceRow(int row1, int row2, Vector& vect, int pos) {
    double multiple{m_matrix[row2][pos] / m_matrix[row1][pos]};
    for (std::ptrdiff_t i{}; i < std::ssize(m_matrix[row2]); ++i) {
        m_matrix[row2][i] -= m_matrix[row1][i]*multiple;
    }
    //augment implementation
    vect.m_vector[row2] -= vect.m_vector[row1]*multiple;
}
Matrix Matrix::gaussianElimination(Vector& vect) const{
    if (vect.m_vector.empty()) {
        vect.m_vector.resize(std::ssize(m_matrix));
    }

    if (std::ssize(m_matrix) != std::ssize(vect.m_vector)) {
        throw std::invalid_argument ("# of rows and # of solutions do not match. \n");
    }

    Matrix newMatrix {m_matrix};
    //row swapping
    for (std::ptrdiff_t i{}; i < std::ssize(newMatrix.m_matrix); ++i) {

        double maxPivot{};
        int pivotIndex{static_cast<int>(i)};
        for (std::ptrdiff_t j{i}; j < std::ssize(newMatrix.m_matrix); ++j) {
            if (std::abs(newMatrix.m_matrix[j][i]) > std::abs(maxPivot)) {
                maxPivot = newMatrix.m_matrix[j][i];
                pivotIndex = static_cast<int>(j);
            }
        }
        newMatrix.swapRows(static_cast<int>(i),pivotIndex, vect);

        //row reduction
        for (std::ptrdiff_t k{i+1}; k < std::ssize(newMatrix.m_matrix); ++k) {
            if (newMatrix.m_matrix[k][i] == 0) {
                continue;
            }
            newMatrix.reduceRow(static_cast<int>(i), static_cast<int>(k), vect, static_cast<int>(i));
        }
    }



    return newMatrix;
}
Vector Matrix::solveMatrix(Vector& vect) const{
    //i am checking for zero row here by adding entire final row
    for (std::ptrdiff_t i{}; i < std::ssize(m_matrix); ++i) {
        double checkSum{};
        for (std::ptrdiff_t j{}; j < std::ssize(m_matrix[0]); ++j) {
            checkSum+=std::abs(m_matrix[i][j]);
        }
        if (checkSum <= 1e-9) {
            if (std::abs(vect.m_vector[i]) <= 1e-9) {
                throw std::invalid_argument("Infinite solutions. \n");
            }
            else {
                throw std::invalid_argument("No solutions. \n");
            }
        }
    }

    //back substitution process

    //here, creating the starting solution vector initialized with all zeros
    Vector answer {vect.m_vector};
    Vector solutions {std::vector<double>{}};
    solutions.m_vector.resize(std::ssize(m_matrix));


    for (std::ptrdiff_t i{std::ssize(m_matrix)-1}; i >=0; --i) {
        for (std::ptrdiff_t j{}; j < std::ssize(m_matrix[0]); ++j) {
            if (i == j) {
                continue;
            }
            answer.m_vector[i]-= m_matrix[i][j]*solutions.m_vector[j];
        }
        //divide answer by divisor of selected digit, then append that to solution vector
        solutions.m_vector[i] = answer.m_vector[i]/m_matrix[i][i];

    }


    return solutions;

}


