#include <iostream>
#include "Matrix.h"
#include "Application.h"
#include "Lexer.h"







int main () {

    // Application App;
    // App.run();

    std::string inp;
    std::getline(std::cin, inp);
    Lexer x{inp};
    x.lexingLoop();
    std::vector<Token> y {x.translateToTokens()};
    for (const auto& token : y) {
        std::string typeName;
        switch (token.type) {
            case TokenType::IDENTIFIER:    typeName = "IDENTIFIER"; break;
            case TokenType::NUMBER:        typeName = "NUMBER"; break;
            case TokenType::LEFT_BRACKET:  typeName = "LEFT_BRACKET"; break;
            case TokenType::RIGHT_BRACKET: typeName = "RIGHT_BRACKET"; break;
            case TokenType::PLUS:          typeName = "PLUS"; break;
            case TokenType::MINUS:         typeName = "MINUS"; break;
            case TokenType::STAR:          typeName = "STAR"; break;
            case TokenType::EQUALS:        typeName = "EQUALS"; break;
            case TokenType::SEMICOLON:     typeName = "SEMICOLON"; break;
            case TokenType::END:           typeName = "END"; break;
        }
        std::cout << typeName << " ('" << token.content << "')\n";
    }


    return 0;
}