#include <iostream>
#include <string>
#include <fstream>

void SaveFile() {
	std::string s;
	std::ofstream o("abc.txt");
	
	std::cin >> s;
	for (int i = 0; i < 3; i++) {
		o << s;
	}
	o.close();
}

void ReadFile() {
	std::string s;
	std::ifstream i("readme.txt");
	if (i.is_open()) {
		while (std::getline(i, s)) {
			std::cout << s << std::endl;
		}
	}
}

int main() {
	ReadFile();
}