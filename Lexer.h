#pragma once
#include <string>
#include "Matrix.h"
#include "Vector.h"

enum class TokenType {
    IDENTIFIER,
    NUMBER,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    PLUS,
    MINUS,
    STAR,
    EQUALS,
    SEMICOLON,
    END,
};

struct Token {
    TokenType type;
    std::string content;
};
class Lexer {
private:
    std::string source;
    std::vector<Token> tokens;
    int start{};
    int current{};

    //helper functions i made
    bool isAtEnd() {
        if (current>=source.length())
            return true;
        return false;
    }
    char advance() {
        return source[current++];
    }
    char check() {
        if (isAtEnd())
            return '\0';
        return source[current];
    }
    char checkNext() {
        if (current + 1 >= source.length())
            return '\0';
        return source[current + 1];
    }
    void addToken(TokenType type) {
        Token newToken;
        newToken.type = type;
        newToken.content = source.substr(start, current-start);
        tokens.push_back(newToken);
    }

public:

    Lexer(std::string_view str)
        :source {str}
    {
    }

    std::vector<Token> translateToTokens();
    void lexingLoop();
    void lexToken();
};