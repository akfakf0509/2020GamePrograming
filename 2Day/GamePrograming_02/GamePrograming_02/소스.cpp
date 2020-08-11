#include <iostream>

template<typename T>
T getMax(T a, T b) {
	return a > b ? a : b;
}

template<typename T1, typename T2>
void ShowData(T1 t1, T2 t2) {
	std::cout << t1 << " + " << t2 << std::endl;
}

int main() {
	//int x = 1, y = 2;
	//float x1 = 1, y1 = 2;

	//std::cout << getMax(x, y) << std::endl;
	//std::cout << getMax(x1, y1) << std::endl;

	char c = 'a';
	int a = 1;
	float b = 1.1;

	ShowData(a, b);
	ShowData(b, c);
	ShowData(a, c);
}