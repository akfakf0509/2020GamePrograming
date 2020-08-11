#include <iostream>
#include <fstream>

int main() {
	std::ifstream ftxt;
	std::string s;
	ftxt.open("readme.txt");

	ftxt >> s;
	std::cout << s;

	ftxt.close();

	std::ofstream otxt;
	std::string str;

	otxt.open("tmp.txt");

	std::cin >> str;
	otxt << str;

	otxt.close();
}