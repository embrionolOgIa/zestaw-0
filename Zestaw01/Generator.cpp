#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}

	int n = std::atoi(argv[1]);
	if (n <= 0 || n > 1000000) {
		return 1;
	}

	std::srand(std::time(nullptr));

	std::cout << n << std::endl;

	for (int i = 0; i < n; ++i) {
		int op = std::rand() % 3;

		if (op == 0) {
			int x = std::rand() % 1000001;
			std::cout << "A " << x << std::endl;
		}
		else if (op == 1) {
			std::cout << "D" << std::endl;
		}
		else {
			std::cout << "S" << std::endl;
		}
	}

	return 0;
}

