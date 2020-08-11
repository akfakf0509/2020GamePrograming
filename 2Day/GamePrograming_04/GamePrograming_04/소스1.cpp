#include <iostream>
#include <queue>

int main() {
	std::queue<int> q;

	q.push(4);
	q.push(3);
	q.push(2);
	q.pop();

	std::cout << q.front() << std::endl;
	std::cout << q.back() << std::endl;
	std::cout << q.empty() << std::endl;
	std::cout << q.size() << std::endl;
}