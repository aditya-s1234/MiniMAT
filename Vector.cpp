//
// Created by Aditya Subramanian on 8/13/26.
//

#include "Vector.h"

void Vector::printVector() const{
    for (const auto& x : m_vector) {
        std::cout << x << '\n';
    }
}
