#pragma once

#include "Lexer.h"
#include "Matrix.h"
#include <vector>


class Parser {
private:
    std::vector<Token> tokens {};
    int current{};
    std::unordered_map<std::string, Matrix> names;

    Token& peek() {
        return tokens[current];
    }

    Token& peekAhead() {
        if (current + 1 >= std::ssize(tokens))
            return tokens.back();
        return tokens[current + 1];
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
    Parser() = default;
    Parser(const std::vector<Token>& t)
    {
        setTokens(t);
    }

    void setTokens(const std::vector<Token>& t){
        tokens = t;
        current = 0;
    }

    Matrix parseMatrix();
    Matrix parsePrimary();
    Matrix parseFactor();
    Matrix parseTerm();
    Matrix parseExpression();


};