#include <iostream>
#include <vector>

void print(const std::vector<int>&);

int main() {
	std::vector<int> vec{ 10,20,30 };
	print(vec);

	vec[0] = 100;
	vec.at(1) = 200;

	print(vec);

	vec.push_back(400);
	print(vec);

	vec.pop_back();
	print(vec);

	std::cout << std::endl;
}

void print(const std::vector<int>& v) {
	for (auto elem : v) {
		std::cout << elem << std::endl;
	}
}