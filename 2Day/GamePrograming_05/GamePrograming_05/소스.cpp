#include <iostream>
#include <vector>

int main() {
	std::vector<double> vec(10);

	std::cout << "Input 10 numbers" << std::endl;

	for (double& elem : vec) {
		std::cin >> elem;
	}

	for (double elem : vec) {
		std::cout << elem << std::endl;
	}
}