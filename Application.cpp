

#include "Application.h"


void Application::run() {
    std::cout << "Welcome to MiniMAT, a lightweight linear algebra engine that can do matrix operations and solve linear equations. \n";
    std::cout << "Please select one of the options below, or enter '-1' to quit: \n";

    while (true){
        std::cout << "[1] Create and store a matrix \n"
                     "[2] Create and store a vector \n"
                     "[3] Matrix addition/subtraction \n"
                     "[4] Matrix multiplication \n"
                     "[5] Scalar multiplication \n"
                     "[6] Transpose matrix \n"
                     "------Advanced linear algebra functions------ \n"
                     "[7] Gaussian elimination \n"
                     "[8] Solve Ax = b\n"
                     "[9] Find determinant of matrix \n"
                     "[10] Find row reduced echelon form of matrix \n"
                     "[11] Find inverse of function \n";
        std::cin >> m_input;

        if (m_input == -1) {
            break;
        }
        matrixOperations();

    }

    std::cout << "Application closing...";
}

void Application::matrixOperations() {
    switch (m_input) {
        case 1: {
            Application::create();
            break;
        }
        case 2: {
            Application::createVect();
            break;
        }
        case 3: {
            Application::add();
            break;
        }
        case 4: {
            Application::mult();
            break;
        }
        case 5: {
            Application::scalar();
            break;
        }
        case 6: {
            Application::transpose();
            break;
        }
        case 7: {
            Application::gaussian();
            break;
        }
        case 8: {
            Application::solve();
            break;
        }
        case 9: {
            Application::determinant();
            break;
        }
        case 10: {
            Application::rref();
            break;
        }
        case 11: {
            Application::inverse();
            break;
        }

        default:
            std::cout << "Invalid input. Please re-enter: \n";
    }
}

//TEMP SOLUTION, CREATE PARSER LATER INSTEAD OF HAVING ALL THIS STUFF REPEATEDLY PRINTED
void Application::create() {
    while (true) {
        int inp{};
        std::cout << "[1] Create matrix \n"
                     "[2] View matrix \n"
                     "[3] Clear List \n"
                     "[4] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1: {
                int row{};
                int col{};
                std::cout << "Enter # of rows: ";
                std::cin >> row;
                std::cout << "Enter # of cols: ";
                std::cin >> col;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Matrix m {row,col};
                m_matrixStorage.push_back(m);
                break;
                }
            case 2: {
                if (m_matrixStorage.empty())
                    std::cout << "No matrices made yet. \n";
                else {
                    int index{};
                    std::cout << "Enter matrix you want to view (index): ";
                    std::cin >> index;
                    if (index >= std::ssize(m_matrixStorage))
                        std::cout << "Invalid index. \n";
                    else
                        m_matrixStorage[index].printMatrix();
                }
                break;
            }
            case 3: {
                m_matrixStorage = {};
                std::cout << "Storage has been wiped. \n";
                break;
            }
            case 4: {
                return;
            }
            default:
                std::cout << "Invalid input. \n";
                break;
        }
    }
}
void Application::createVect() {
    while (true) {
        int inp{};
        std::cout << "[1] Create vector \n"
                     "[2] View vector \n"
                     "[3] Clear List \n"
                     "[4] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1: {
                int row{};
                std::cout << "Enter # of entries: ";
                std::cin >> row;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Vector v {row};
                m_vectorStorage.push_back(v);
                break;
            }
            case 2: {
                if (m_vectorStorage.empty())
                    std::cout << "No vectors made yet. \n";
                else {
                    int index{};
                    std::cout << "Enter vector you want to view (index): ";
                    std::cin >> index;
                    if (index >= std::ssize(m_vectorStorage))
                        std::cout << "Invalid index. \n";
                    else
                        m_vectorStorage[index].printVector();
                }
                break;
            }
            case 3: {
                m_vectorStorage = {};
                std::cout << "Storage has been wiped. \n";
                break;
            }
            case 4: {
                return;
            }
            default:
                std::cout << "Invalid input. \n";
                break;
        }
    }
}
void Application::add() {
    while (true) {
        int inp{};
        std::cout << "[1] Add matrices \n"
                     "[2] Subtract matrices \n"
                     "[3] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1:
            case 2: {
                if (std::ssize(m_matrixStorage)<=1) {
                    std::cout << "You must have at least 2 matrices in storage to add/subtract. \n";
                    break;
                }
                else {
                    int ind1{};
                    int ind2{};
                    std::cout << "Input index of first matrix. \n";
                    std::cin >> ind1;
                    std::cout << "Input index of second matrix. \n";
                    std::cin >> ind2;
                    if (ind1 < 0 || ind1 >= std::ssize(m_matrixStorage) || ind2 < 0 || ind2 >= std::ssize(m_matrixStorage)) {
                        std::cout << "Invalid index entered.\n";
                        break;
                    }
                    if (inp == 1) {
                        try {
                            Matrix sum = m_matrixStorage[ind1].addMatrix(m_matrixStorage[ind2]);
                            m_matrixStorage.push_back(sum);
                            sum.printMatrix();
                            std::cout << "Added to index " << std::ssize(m_matrixStorage) - 1 << '\n';
                        } catch (const std::invalid_argument& e) {
                            std::cout << "Error: " << e.what() << '\n';
                        }
                    }
                    else {
                        try {
                            Matrix diff = m_matrixStorage[ind1].subtractMatrix(m_matrixStorage[ind2]);
                            m_matrixStorage.push_back(diff);
                            diff.printMatrix();
                            std::cout << "Added to index " << std::ssize(m_matrixStorage) - 1 << '\n';
                        } catch (const std::invalid_argument& e) {
                            std::cout << "Error: " << e.what() << '\n';
                        }
                    }
                }

            }
            case 3:
                return;
            default:
                std::cout << "Invalid input.\n";
                break;


        };
    }
}
void Application:: mult() {
    while (true) {
        int inp{};
        std::cout << "[1] Multiply matrices \n"
                     "[2] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1:
                {
                if (std::ssize(m_matrixStorage)<=1) {
                    std::cout << "You must have at least 2 matrices in storage to multiply. \n";
                    break;
                }
                else {
                    int ind1{};
                    int ind2{};
                    std::cout << "Input index of first matrix. \n";
                    std::cin >> ind1;
                    std::cout << "Input index of second matrix. \n";
                    std::cin >> ind2;
                    if (ind1 < 0 || ind1 >= std::ssize(m_matrixStorage) || ind2 < 0 || ind2 >= std::ssize(m_matrixStorage)) {
                        std::cout << "Invalid index entered.\n";
                        break;
                    }
                    try {
                        Matrix product {m_matrixStorage[ind1].multiplyMatrix(m_matrixStorage[ind2])};
                        m_matrixStorage.push_back(product);
                        product.printMatrix();
                        std::cout << "Added to index " << std::ssize(m_matrixStorage) - 1 << '\n';
                    } catch (const std::invalid_argument& e) {
                        std::cout << "Error: " << e.what() << '\n';
                    }
                }

            }
            case 2:
                return;
            default:
                std::cout << "Invalid input.\n";
                break;


        };
    }
};
void Application::scalar() {
    while (true) {
        int inp{};
        std::cout << "[1] Multiply matrix by scalar \n"
                     "[2] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1:
            {
                if (std::ssize(m_matrixStorage)<1) {
                    std::cout << "You must have at least 1 matrix in storage to multiply it by a scalar. \n";
                    break;
                }
                int ind1{};
                std::cout << "Input index of the matrix. \n";
                std::cin >> ind1;

                if (ind1 < 0 || ind1 >= std::ssize(m_matrixStorage)) {
                    std::cout << "Invalid index entered.\n";
                    break;
                }
                double scalar{};
                std::cout << "Enter scalar: \n";
                std::cin >> scalar;
                Matrix scaled {m_matrixStorage[ind1].multiplyScalar(scalar)};
                scaled.printMatrix();
                m_matrixStorage.push_back(scaled);
                std::cout << "Added to index " << std::ssize(m_matrixStorage) - 1 << '\n';
            }
            case 2:
                return;
            default:
                std::cout << "Invalid input.\n";
                break;
        };
    }
};
void Application::transpose() {
    while (true) {
        int inp{};
        std::cout << "[1] Transpose matrix \n"
                     "[2] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1:
            {
                if (std::ssize(m_matrixStorage)<1) {
                    std::cout << "You must have at least 1 matrix in storage to transpose it. \n";
                    break;
                }
                int ind1{};
                std::cout << "Input index of the matrix. \n";
                std::cin >> ind1;

                if (ind1 < 0 || ind1 >= std::ssize(m_matrixStorage)) {
                    std::cout << "Invalid index entered.\n";
                    break;
                }
                Matrix transpose {m_matrixStorage[ind1].transposeMatrix()};
                transpose.printMatrix();
                m_matrixStorage.push_back(transpose);
                std::cout << "Added to index " << std::ssize(m_matrixStorage) - 1 << '\n';

            }
            case 2:
                return;
            default:
                std::cout << "Invalid input.\n";
                break;


        };
    }
};
void Application::gaussian() {
    while (true) {
        int inp {};
        std::cout << "[1] Perform gaussian elimination on a matrix \n"
                     "[2] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1: {
                if (std::ssize(m_matrixStorage)<1) {
                    std::cout << "You must have at least 1 matrix in storage to perform gaussian elimination. \n";
                    break;
                }
                int index{};
                std::cout << "Input index of the matrix: ";
                std::cin >> index;
                if (index<0 || index >= std::ssize(m_matrixStorage)) {
                    std::cout << "Invalid index entered. \n";
                    break;
                }
                Vector blank {};

                Matrix gauss {m_matrixStorage[index].gaussianElimination(blank)};
                gauss.printMatrix();
                m_matrixStorage.push_back(gauss);
                std::cout << "Added to index " << std::ssize(m_matrixStorage) - 1 << '\n';
                break;
            }
            case 2:
                return;
            default:
                std::cout << "Invalid input. \n";
                break;
        }
    }
}
void Application::solve() {
    while (true) {
        int inp {};
        std::cout << "[1] Solve Ax = b for x \n"
                     "[2] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1: {
                if (std::ssize(m_matrixStorage)<1 || std::ssize(m_vectorStorage) < 1) {
                    std::cout << "You must have at least 1 matrix and vector in storage to solve it. \n";
                    break;
                }
                int indexm{};
                int indexv{};
                std::cout << "Input index of the matrix: ";
                std::cin >> indexm;
                std::cout << "Input index of the vector: ";
                std::cin >> indexv;
                if (indexm<0 || indexm >= std::ssize(m_matrixStorage) || indexv<0 || indexv >= std::ssize(m_vectorStorage)) {
                    std::cout << "Invalid index entered. \n";
                    break;
                }

                //i did this so that the vector in vectrstorage wont get modified
                try {
                    Vector b {m_vectorStorage[indexv]};
                    Matrix upper {m_matrixStorage[indexm].gaussianElimination(b)};
                    Vector sol {upper.solveMatrix(b)};
                    sol.printVector();
                    m_vectorStorage.push_back(sol);
                    std::cout << "Added to index " << std::ssize(m_vectorStorage) - 1 << '\n';

                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Error: " << e.what() << '\n';
                }

            }
            case 2:
                return;
            default:
                std::cout << "Invalid input. \n";
                break;
        }
    }
}
void Application::determinant() {
    while (true) {
        int inp {};
        std::cout << "[1] Solve determinant of matrix \n"
                     "[2] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1: {
                if (std::ssize(m_matrixStorage)<1) {
                    std::cout << "You must have at least 1 matrix in storage to find it's determinant. \n";
                    break;
                }
                int indexm{};
                std::cout << "Input index of the matrix: ";
                std::cin >> indexm;
                if (indexm<0 || indexm >= std::ssize(m_matrixStorage)) {
                    std::cout << "Invalid matrixindex entered. \n";
                    break;
                }
                try {
                    Vector blank{};
                    Matrix upper {m_matrixStorage[indexm].gaussianElimination(blank)};
                    upper.printMatrix();
                    std::cout << "The determinant of this matrix is " << upper.findDeterminant() << '\n';
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Error: " << e.what() << '\n';
                }
                break;
            }
            case 2:
                return;
            default:
                std::cout << "Invalid input. \n";
                break;
        }
    }
}
void Application::rref() {
    while (true) {
        int inp {};
        std::cout << "[1] Solve for row reduced echelon form of matrix \n"
                     "[2] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1: {
                if (std::ssize(m_matrixStorage)<1) {
                    std::cout << "You must have at least 1 matrix in storage to find it's RREF. \n";
                    break;
                }
                int indexm{};
                std::cout << "Input index of the matrix: ";
                std::cin >> indexm;
                if (indexm<0 || indexm >= std::ssize(m_matrixStorage)) {
                    std::cout << "Invalid matrix index entered. \n";
                    break;
                }
                Vector blank{};
                Matrix reduce {m_matrixStorage[indexm].rref(blank)};
                reduce.printMatrix();
                m_matrixStorage.push_back(reduce);
                std::cout << "Matrix added to index " << std::ssize(m_matrixStorage)-1;
            }
            case 2:
                return;
            default:
                std::cout << "Invalid input. \n";
                break;
        }
    }
}
void Application::inverse() {
    while (true) {
        int inp {};
        std::cout << "[1] Solve for inverse of matrix \n"
                     "[2] Return \n";
        std::cin >> inp;
        switch (inp) {
            case 1: {
                if (std::ssize(m_matrixStorage)<1) {
                    std::cout << "You must have at least 1 matrix in storage to find it's RREF. \n";
                    break;
                }
                int indexm{};
                std::cout << "Input index of the matrix: ";
                std::cin >> indexm;
                if (indexm<0 || indexm >= std::ssize(m_matrixStorage)) {
                    std::cout << "Invalid matrix index entered. \n";
                    break;
                }
                try {
                   Matrix inverse {m_matrixStorage[indexm].inverseMatrix()};
                    inverse.printMatrix();
                    m_matrixStorage.push_back(inverse);
                    std::cout << "Matrix added to index " << std::ssize(m_matrixStorage)-1;
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Error: " << e.what() << '\n';
                }
            }
            case 2:
                return;
            default:
                std::cout << "Invalid input. \n";
                break;
        }
    }
}