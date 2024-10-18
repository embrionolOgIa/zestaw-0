#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
#include "LinkedStack.hpp"

class InfixToPostfixConverter {
public:
    static std::string convert(const std::string& infix) {
        LinkedStack stack(100);  // Assuming a max size of 100 for the stack
        std::string postfix;
        std::unordered_map<char, int> precedence = {
            {'+', 1}, {'-', 1},
            {'*', 2}, {'/', 2},
            {'^', 3}
        };

        for (char token : infix) {
            if (std::isspace(token)) {
                continue; // Ignore whitespace
            } else if (std::isalnum(token)) {
                postfix += token; // Add operands to postfix expression
            } else if (token == '(') {
                stack.linkedPush(token);
            } else if (token == ')') {
                while (!stack.linkedEmpty() && stack.top() != '(') {
                    postfix += stack.linkedPop();
                }
                stack.linkedPop(); // Pop the '(' from the stack
            } else { // Operator
                while (!stack.linkedEmpty() && precedence[stack.top()] >= precedence[token]) {
                    postfix += stack.linkedPop();
                }
                stack.linkedPush(token);
            }
        }

        // Pop all the operators from the stack
        while (!stack.linkedEmpty()) {
            postfix += stack.linkedPop();
        }

        return postfix;
    }
};

int main() {
    std::string infix = "A+B*(C^D-E)";
    std::string postfix = InfixToPostfixConverter::convert(infix);
    std::cout << "Infix: " << infix << std::endl;
    std::cout << "Postfix: " << postfix << std::endl;

    return 0;
}

