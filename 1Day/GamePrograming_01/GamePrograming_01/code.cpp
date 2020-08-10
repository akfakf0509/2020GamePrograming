#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Car.h"

int main() {
	srand(time(NULL));
	srand(GetTickCount());

	Car car1 = Car(std::rand() % 200, 1, "red"), car2 = Car(std::rand() % 200, 1, "red");

	car1.show();
	car2.show();

	if (car1.getSpeed() > car2.getSpeed()) {
		std::cout << "Car1 is win" << std::endl;
	}
	else {
		std::cout << "Car2 is win" << std::endl;
	}
}