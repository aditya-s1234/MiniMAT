//
// Created by Aditya Subramanian on 8/13/26.
//

#include "Application.h"


void Application::run() {
    std::cout << "Welcome to MiniMAT, a lightweight linear algebra engine that can do matrix operations and solve linear equations. \n";
    std::cout << "Please select one of the options below, or enter '-1' to quit: \n";

    while (true){
        std::cout << "[1] Create and store a matrix \n"
                     "[2] Matrix addition/subtraction \n"
                     "[3] Matrix multiplication \n"
                     "[4] Scalar multiplication \n"
                     "[5] Transpose matrix \n";
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
            Application::add();
            break;
        }
        case 3: {
            Application::mult();
            break;
        }
        case 4: {
            Application::scalar();
            break;
        }
        case 5: {
            Application::transpose();
            break;
        }
        default:
            std::cout << "Invalid input. Please re-enter: ";
    }
}

//TEMP SOLUTION, CREATE PARSER LATER
void Application::create() {
    while (true) {
        int inp{};
        std::cout << "[1] Create matrix \n"
                     "[2] View matrix \n";
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
                    m_matrixStorage[index].printMatrix();
                }
                break;
            }
            default:
                std::cout << "Invalid input. \n";
                break;
        }
    }
}
void Application::add() {};
void Application:: mult() {};
void Application::scalar() {};
void Application::transpose() {};