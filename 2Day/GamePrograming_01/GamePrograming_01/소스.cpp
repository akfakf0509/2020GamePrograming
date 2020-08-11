#include <iostream>
#include "NoPersonExceptions.h"

int main() {
	int pizza_slices = 0;
	int persons = 1;
	int slices_per_person = 0;

	try {
		std::cin >> pizza_slices;
		std::cin >> persons;

		if (persons <= 0)
			throw NoPersonExceptions(persons);

		slices_per_person = pizza_slices / persons;

		std::cout << slices_per_person << std::endl;
	}
	catch (NoPersonExceptions e) {
		std::cout << "Exceptions : person is " << e.getPersons() << std::endl;;
	}
}