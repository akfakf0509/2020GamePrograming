#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename Iter>
void print(const Iter&, const Iter&);
template<typename Iter>
void print_reverse(const Iter&, const Iter&);

int main() {
	vector<int> v{ 1, 2, 3, 4 };
	list<double> l{ 1.1,2.2,3.3,4.4 };
	int ary[] = { 100, 200, 300, 400 };

	print(v.begin(), v.end());
	print(l.begin(), l.end());
	print(begin(ary), end(ary));

	print_reverse(v.begin(), v.end());
	print_reverse(l.begin(), l.end());
	print_reverse(begin(ary), end(ary));
}

template<typename Iter>
void print(const Iter& iter_begin, const Iter& iter_end) {
	for (Iter iter = iter_begin; iter != iter_end; iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

template<typename Iter>
void print_reverse(const Iter& iter_begin, const Iter& iter_end) {
	Iter iter = iter_end;

	while (iter != iter_begin) {
		iter--;
		cout << *iter << " ";
	}
	cout << endl;
}