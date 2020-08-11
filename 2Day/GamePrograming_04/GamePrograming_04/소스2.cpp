#include <iostream>
#include <vector>

int main() {
	double sum = 0.0;
	const int NUMBBER_OF_ENTRIES = 5;
	std::vector<double> numbers(NUMBBER_OF_ENTRIES);

	for (int i = 0; i < NUMBBER_OF_ENTRIES; i++) {
		std::cin >> numbers[i];
		sum += numbers[i];
	}

	std::cout << "args : ";

	for (int i = 0; i < NUMBBER_OF_ENTRIES - 1; i++) {
		std::cout << numbers[i] << ", ";
	}

	std::cout << numbers[NUMBBER_OF_ENTRIES - 1];
	std::cout << sum / NUMBBER_OF_ENTRIES;
}