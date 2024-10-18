#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <sstream>
#include "onpstacklib.hpp"

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isLeftAssociative(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}
std::string infixToPostfix(const std::string& infix) {
    LinkedStack stack(1000000);
    std::string postfix;
    std::istringstream iss(infix);
    std::string token;

    while (iss >> token) {
        if (std::isdigit(token[0])) {
            postfix += token + " "; // Add operand to postfix expression
        } else if (token[0] == '(') {
            stack.linkedPush('('); // Push '(' onto the stack
        } else if (token[0] == ')') {
            while (!stack.linkedEmpty() && stack.top() != '(') {
                postfix += static_cast<char>(stack.linkedPop()) + " "; // Pop and add to postfix
            }
            stack.linkedPop(); // Pop the '(' from the stack
        } else { // Operator
            while (!stack.linkedEmpty() && precedence(stack.top()) >= precedence(token[0])) {
                if (isLeftAssociative(token[0])) {
                    postfix += static_cast<char>(stack.linkedPop()) + " "; // Pop and add to postfix
                } else {
                    break;
                }
            }
            stack.linkedPush(token[0]); // Push the current operator
        }
    }

    // Pop all the operators from the stack
    while (!stack.linkedEmpty()) {
        postfix += static_cast<char>(stack.linkedPop()) + " ";
    }

    return postfix;
}
int main() {
    std::string infixExpression = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
    std::string postfix = infixToPostfix(infixExpression);
    std::cout << "Postfix: " << postfix << std::endl;
    return 0;
}

