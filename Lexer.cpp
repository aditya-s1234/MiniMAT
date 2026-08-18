#include "Lexer.h"

std::vector<Token> Lexer::translateToTokens() {
    return tokens;
}

//here i am setting start to current so that it wont parse everything from the start every time i am trying to get a new token
void Lexer::lexingLoop() {
    while (!isAtEnd()) {
        start = current;
        lexToken();
    }
    tokens.push_back({TokenType::END, ""});
}

// here if it sees a numer it keeps going bc numbers can be multiple digits before creating a token out of it
//for decimals, it checks if the thing ahead is a decimal (and checking ahead also increments the index as a side effect) and that could also work
void Lexer::lexToken() {
    char x {advance()};
    if (std::isdigit(x)) {
        while (std::isdigit(check())) {
            advance();
        }
        if (check() == '.' && std::isdigit(checkNext())) {
            advance();
            while (std::isdigit(check()))
                advance();
        }
        addToken(TokenType::NUMBER);
        return;
    }
//here  code doesnt care if there are numbers or characters in identifier name as long as it starts with a letter
    else if (std::isalpha(x)) {
        while (std::isalnum(check()) || check() == '_') {
            advance();
        }
        addToken(TokenType::IDENTIFIER);
        return;
    }
    else {
        //here every time it encounters a singular symbol, it will push it to the string so that my addtoken function can retrieve it
        // and then it calls addtoken with its type based on the symbol
        switch (x) {
            case '+':
                addToken(TokenType::PLUS);
                return;
            case '-':
                addToken(TokenType::MINUS);
                return;
            case '*':
                addToken(TokenType::STAR);
                return;
            case '=':
                addToken(TokenType::EQUALS);
                return;
            case '[':
                addToken(TokenType::LEFT_BRACKET);
                return;
            case ']':
                addToken(TokenType::RIGHT_BRACKET);
                return;
            case ';':
                addToken(TokenType::SEMICOLON);
                return;
            case '(':
                addToken(TokenType::LEFT_PAREN);
                return;
            case ')':
                addToken(TokenType::RIGHT_PAREN);
                return;
            case ',':
                addToken(TokenType::COMMA);
                return;
            case ' ':
            case '\n':
            case '\t':
            case '\r':
                return;
            default:
                std::cout << "error. ";
                return;
        }
    }
}

