#include <iostream>
#include "LinkedStack.hpp"
#include "Node.hpp"

int main() {
	int n;
	std::cin >> n;

	LinkedStack stack;

	std::string command;
	int value;

	for (int i = 0; i < n; ++i) {
		std::cin >> command;

		if (command == "A") {
			std::cin >> value;
			stack.linkedPush(value);
		}
		else if (command == "D") {
			try {
				std::cout << stack.linkedPop() << std::endl;
				
			}
			catch (const std::out_of_range& e) {
				std::cout << "EMPTY" << std::endl;
			}
		}
		else if (command == "S") {
			std::cout << stack.linkedSize() << std::endl;
		}
	}

	return 0;
}

