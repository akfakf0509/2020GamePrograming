#include <iostream>
#include <vector>

int main() {
	const int SIZE = 3;
	std::vector<int> a{ 1,2,3 };

	std::cout << "Vector : ";

	for (int i = 0; i < SIZE; i++) {
		std::cout << a.at(i) << ' ';
	}

	std::cout << std::endl;

	for (int i : a) {
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	a[1] = 37;

	for (int i = 0; i < SIZE; i++) {
		std::cout << a[i] << ' ';
	}

	std::cout << std::endl;

	std::vector<int> v(10);
	std::vector<int> v1(10, 1);

	for (int i : v) {
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	for (int i : v1) {
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	return 0;
}