#include "Parser.h"


//will only be called when sees left bracket so dont need to check that
//if content is a num, it converts it to double and pushes it to row

Matrix Parser::parseMatrix() {
    //moves off of the left bracket
    advance();
    std::vector<std::vector<double>> matrix {};
    std::vector<double> row{};

    while (!check(TokenType::END) && !check(TokenType::RIGHT_BRACKET)) {

        if (check(TokenType::NUMBER)) {
            row.push_back(std::stod(tokens[current].content));
        }
        //resetting it to 0, capacity should stay the same. REMEMBER TO DO THIS
        //INSTEAD OF CREATING NEW VECTS FOR MY OTHER FUNCTIONS
        if (check(TokenType::SEMICOLON)) {
            if (!matrix.empty() && std::ssize(matrix[0])!=std::ssize(row))
                throw std::invalid_argument ("All rows must be the same length. \n");
            matrix.push_back(row);
            row.clear();
        }

        advance();
    }
    //pushes in last row (wont have semicolon here
    if (!row.empty()) {
        if (!matrix.empty() && std::ssize(matrix[0])!=std::ssize(row))
            throw std::invalid_argument ("All rows must be the same length. \n");
        matrix.push_back(row);
        row.clear();
    }
    if (check(TokenType::RIGHT_BRACKET))
        advance();

    return matrix;
};

