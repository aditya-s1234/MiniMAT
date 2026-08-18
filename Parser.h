#pragma once

#include "Lexer.h"
#include "Matrix.h"
#include <vector>


class Parser {
private:
    std::vector<Token> tokens {};
    int current{};

    Token& peek() {
        return tokens[current];
    }

    Token& advance() {
        return tokens[current++];
    }

    bool check(TokenType type) {
        if (tokens[current].type == type)
            return true;
        return false;
    }

    bool isAtEnd() {
        if (tokens[current].type == TokenType::END)
            return true;
        return false;
    }

public:


    Matrix parseMatrix();


};