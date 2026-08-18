#include <iostream>
#include "Matrix.h"
#include "Application.h"
#include "Lexer.h"
#include "Parser.h"
int main () {

    Parser parse{};
    // Application App;
    // App.run();
    while (true) {
        std::cout << "MiniMAT>> ";
        std::string line;
        std::getline(std::cin, line);
        if (!std::cin) {
            break;
        }
        if (line == "quit" || line == "q")
            break;
        Lexer x {line};
        x.lexingLoop();
        parse.setTokens(x.translateToTokens());
        try {
            parse.parseExpression();
        }
        catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        }



    }




    return 0;
}