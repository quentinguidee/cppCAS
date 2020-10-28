#include <core/nodes/expressions/values/unknown.hpp>
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

        std::cout << "== TREE ==";
        std::cout << ParseTree(tokens).toString() << "\n\n";

        Expression &expression = ParseTree(tokens).getExpression();
        Unknown x{};

        std::cout << "== TESTS ==" << '\n';
        std::cout << "<> String     " << expression.toString() << '\n';
        std::cout << "<> LaTeX      " << expression.toLaTeX() << '\n';
        std::cout << "<> Diff(x)    " << expression.differentiated(x)->toString() << '\n';
        std::cout << "<> Int(x)     " << expression.integrated(x)->toString() << '\n';
        // std::cout << "<> is+        " << expression.isPositive() << '\n';
        // std::cout << "<> is0        " << expression.isZero() << '\n';
        // std::cout << "<> is-        " << expression.isNegative() << '\n';
        std::cout << std::endl;
    }
    return 0;
}
