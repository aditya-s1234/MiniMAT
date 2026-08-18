#include "Parser.h"


//will only be called when sees left bracket so dont need to check that
//if content is a num, it converts it to double and pushes it to row


// how this works is that after a primary is parsed (matrix or num) it then advances to the next, and it is recursively
// called in order of precedence. so then mult then add/sub then equate, and it is solved to the left side

Matrix Parser::parseMatrix() {
    //moves off of the left bracket
    advance();
    std::vector<std::vector<double>> matrix {};
    std::vector<double> row{};

    while (!check(TokenType::END) && !check(TokenType::RIGHT_BRACKET)) {

        if (check(TokenType::NUMBER)) {
            row.push_back(std::stod(advance().content));
        }
        //resetting it to 0, capacity should stay the same. REMEMBER TO DO THIS
        //INSTEAD OF CREATING NEW VECTS FOR MY OTHER FUNCTIONS
        if (check(TokenType::SEMICOLON)) {
            if (!matrix.empty() && std::ssize(matrix[0])!=std::ssize(row))
                throw std::invalid_argument ("All rows must be the same length. \n");
            matrix.push_back(row);
            row.clear();
            advance();
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

Matrix Parser::parsePrimary() {
    switch (peek().type) {
        case (TokenType::LEFT_BRACKET):
            return parseMatrix();

            //need to rewrite scalar multiplication to take in 1x1 matrices instead of just doubles
        case (TokenType::NUMBER):
            return Matrix{{std::stod(advance().content)}};

        case (TokenType::IDENTIFIER): {
            Token token = advance();
            if (!names.contains(token.content)) {
                throw std::invalid_argument(std::format("Variable {} is not in memory. \n", token.content));
            }
            return names[token.content];
        }
        //future goal: add parentheses token and check parentheses.

        default:
            throw std::invalid_argument("Error.");
    }
}

Matrix Parser::parseFactor() {
    Matrix leftSide {parsePrimary()};
    while (peek().type == TokenType::STAR) {
        advance();
        Matrix rightSide {parsePrimary()};
        leftSide = leftSide * rightSide;
    }

    return leftSide;
}

Matrix Parser::parseTerm() {
    Matrix leftSide {parseFactor()};
    while (peek().type == TokenType::PLUS || peek().type == TokenType::MINUS) {
        TokenType sign {peek().type};
        advance();
        Matrix rightSide {parseFactor()};
        if (sign == TokenType::PLUS)
            leftSide+=rightSide;
        else
            leftSide-=rightSide;
    }
    return leftSide;
}

Matrix Parser::parseExpression() {
    if (peek().type == TokenType::IDENTIFIER && peekAhead().type == TokenType::EQUALS) {
        std::string varName {advance().content};
        advance();
        Matrix leftSide {parseTerm()};
        names[varName] = leftSide;
        return leftSide;
    }
    return parseTerm();
}

