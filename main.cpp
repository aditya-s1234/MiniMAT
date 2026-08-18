#include <iostream>
#include "Matrix.h"
#include "Application.h"
#include "Lexer.h"
#include "Parser.h"
int main () {

    Parser parse{};
    // Application App;
    // App.run();
    std::cout << "MiniMAT>> Press h for help. \n";
    while (true) {
        std::cout << "MiniMAT>> ";
        std::string line;
        std::getline(std::cin, line);
        if (!std::cin) {
            break;
        }
        if (line == "quit" || line == "q")
            break;
        if (line == "cli" || line == "CLI") {
            Application App;
            App.run();
            continue;
        }
        if (line == "h") {
            std::cout << "MiniMAT Help\n"
            "-------------\n"
            "Variables:\n"
            "  A = [1 2; 3 4]     Define a matrix (rows separated by ';', values by spaces)\n"
            "  B = [1 2]          Define a 1xN matrix/vector\n"
            "  A                  Reference a previously defined variable\n"
            "\n"
            "Arithmetic:\n"
            "  A + B              Matrix addition\n"
            "  A - B              Matrix subtraction\n"
            "  A * B              Matrix multiplication\n"
            "  (A + B) * C        Parentheses for grouping\n"
            "\n"
            "Functions:\n"
            "  print(A)           Print a matrix\n"
            "  rref(A)            Reduced row echelon form\n"
            "  elim(A)            Gaussian elimination (row echelon form)\n"
            "  inv(A)             Matrix inverse\n"
            "  solve(A, B)        Solve Ax = B for x\n"
            "\n"
            "Other:\n"
            "  h                  Show this help message\n"
            "  q / quit           Exit MiniMAT\n"
            "  cli / CLI.         Access CLI \n";
            continue;
        }
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