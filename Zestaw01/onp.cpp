#include <iostream>
#include <string>
#include <cctype>
#include "onpstacklib.hpp"

int evaluation(char oper) {

	if (oper == '+' || oper == '-') {
		return 1;
	} 
	else if (oper == '*' || oper == '/') {
		return 2;
	} 
	else {
		return -1;
	}
}

bool isoperator(char ch) {

	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isother(char ch) {

	return ch == '(' || ch == ')' || ch == ' ';
}

void onpconverter(std::string expression) {

	std::string onpnotation = "";
	std::string leftop = "";
	onpstacklib stack;
	stack.linkedPush('0');
    

	for (size_t i = 0; i < expression.length(); i++) {
	
		if (isdigit(expression[i]) || isalpha(expression[i])) {
			onpnotation += expression[i];

			// spacja jeśli to pojedyncza cyfra
			if (i + 1 >= expression.length() || !isdigit(expression[i + 1])) {
				onpnotation += ' ';
			}
		}

		if (isoperator(expression[i]) || isother(expression[i])) {
			if (expression[i] == '(') {
				stack.linkedPush(expression[i]);
			} 
			else if (expression[i] == ')') {
				while (stack.top() != '(') {
					onpnotation += stack.linkedPop();
					onpnotation += ' '; // Dodaj spację po operatorze
				}
				stack.linkedPop(); // Usuwamy '('
			} 
			else if (expression[i] == ' ') {
				continue; // Ignoruj spacje
			} 
			else {
				while (!stack.linkedEmpty() && evaluation(stack.top()) >= 
				evaluation(expression[i])) {
					onpnotation += stack.linkedPop();
					onpnotation += ' '; // Dodaj spację po operatorze
				}
				stack.linkedPush(expression[i]);
			}
         
		}
	}

	while (!stack.linkedEmpty() && stack.top() != '0' && stack.top() != ' ') {
		leftop += stack.linkedPop();
	}
	if(leftop.length() == 0){
		if (!onpnotation.empty() && onpnotation.back() == ' ') {
			onpnotation.pop_back();
		}
	}
	
	std::cout << onpnotation << leftop;
}

int main() {

	std::string exp;
	std::getline(std::cin, exp); // aby uwzględnić spacje
	onpconverter(exp);
}

