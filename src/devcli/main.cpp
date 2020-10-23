#include <iostream>
#include <parser/lexer.hpp>
#include <parser/parse_tree.hpp>
#include <parser/parser.hpp>

int main()
{
    while (true)
    {
        std::cout << "====================================" << '\n';

        std::string input;
        std::cin >> input;

        std::vector<Token> tokens = Lexer::execute(input);

        std::cout << "== TOKENS ==" << '\n';
        std::cout << Lexer::tokensToString(tokens) << "\n\n";

        tokens = Parser::reorderTokens(tokens);

        std::cout << "== TOKENS (Shunting Yard) ==" << '\n';
        std::cout << Lexer::tokensToString(tokens) << "\n\n";

        std::cout << "== TREE ==" << '\n';
        std::cout << ParseTree(tokens).toString() << "\n\n";

        std::cout << "== EXPRESSION ==" << '\n';
        std::cout << ParseTree(tokens).getExpression().simplified()->toString() << '\n';
        std::cout << ParseTree(tokens).getExpression().simplified()->toLaTeX() << '\n'
                  << std::endl;
    }
    return 0;
}
