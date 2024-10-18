#include <iostream>
#include "LinkedStack.hpp"
#include "Node.hpp"

int main() {
	int n;
	std::cin >> n;

	LinkedStack stack(1000000); // inicjalizacja stosu o maksymalnej pojemnosci

	std::string command;
	int value;

	for (int i = 0; i < n; ++i) {
		std::cin >> command;

		if (command == "A") {
        		std::cout << "dodajemy randomowa wartosc na stos\n";
			std::cin >> value;
			stack.linkedPush(value);
		}
		else if (command == "D") {
			try {
				std::cout << "bierzemy wartosc ze stosu\n";
				int poppedValue = stack.linkedPop();
				//std::cout << poppedValue << std::endl;
			}
			catch (const std::out_of_range& e) {
				std::cout << "EMPTY" << std::endl;
			}
		}
		else if (command == "S") {
			stack.linkedSize();
		}
	}

	return 0;
}

