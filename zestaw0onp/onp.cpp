#include <iostream>
#include <string>
#include <cctype>
#include "LinkedStack.hpp"


int evaluation(char oper){
	if(oper == '+' || oper == '-'){
		return 1;
	}
	else if(oper == '*' || oper == '/'){
		return 2;
	}
	else{
		return -1;
	}
}
bool isoperator(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
		return true;
	}
	else{
		return false;
	}
}

bool isother(char ch){
	if (ch == '(' || ch == ')' || ch == ' '){
		return true;
	}
	else{
		return false;
	}
}
void onpconverter(std::string expression){
	
	size_t k;
	std::string onpnotation = "";
	std::string leftop = "";
	LinkedStack stack;
	stack.linkedPush('0');
	
	for (size_t i = 0; i < expression.length(); i++) {

		if (isdigit(expression[i]) || isalpha(expression[i])) {
			onpnotation += expression[i];
			std::cout<<"wyjscie:\n"<<onpnotation<<std::endl;
		}
		
		if (isoperator(expression[i])>0 || isother(expression[i]) == true ){
		
			if (expression[i] == '('){
				std::cout<<"mamy nawias ( -> dodany na stos"<<std::endl;
				stack.linkedPush(expression[i]);
			}
			else if (expression[i] == ')'){
				while(stack.top() != '('){
					onpnotation += stack.linkedPop();;
					std::cout<<"mamy nawias ) wyjscie:\n" << 
					onpnotation<<std::endl;
					
				}
				stack.linkedPop();
			}
				
			else if (!stack.linkedEmpty() && evaluation(stack.top()) < 
			evaluation(expression[i])){
				stack.linkedPush(expression[i]);
			}
			else if ( expression[i] == ' '){
				continue;
			}
			else{
				onpnotation += stack.linkedPop();
				std::cout<<"wyjscie:\n"<<onpnotation<<std::endl;
				stack.linkedPush(expression[i]);
			}
				
		}
	}
	
	// dodaj wartosci ktore dostaly na stosie na koniec stosu
    
	while (!stack.linkedEmpty()) {
		leftop += stack.linkedPop();
	}

	for (k = 0; k < leftop.length() - 1; k++) {
		if(isoperator(leftop[k])){
			std::cout << "\npozostale wartosci ze stosu: "<< leftop[k];
		}
	}
	// usuwam 0
	leftop[k]='\n';
	
	std::cout<<"\n\nto twoje wyrazenie w onp to "<< onpnotation << leftop<<  std::endl;
}
	
	
int main() {
	std::string exp;
	std::cout<<"podaj wyrazenie w notacji infix"<<std::endl;
	std::cin>>exp;
	onpconverter(exp);
	//std::cout<<exp<<std::endl;
}

