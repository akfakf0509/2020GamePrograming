#include "Car.h"

Car::Car(int speed, int gear, std::string pcolor) :speed(speed), gear(gear), pcolor(pcolor) {
}

int Car::getSpeed() {
	return speed;
}
int Car::getGear() {
	return gear;
}
std::string Car::getPcolor() {
	return pcolor;
}

void Car::setSpeed(int speed_) {
	speed = speed_;
}
void Car::setGear(int gear_) {
	gear = gear_;
}
void Car::setPcolor(std::string pcolor_) {
	pcolor = pcolor_;
}

void Car::speedUp() {
	speed += 10;
}
void Car::speedDown() {
	speed -= 10;
}
void Car::show() {
	std::cout << "=========" << std::endl;
	std::cout << "speed : " << speed << std::endl;
	std::cout << "gear : " << gear << std::endl;
	std::cout << "color : " << pcolor << std::endl;
	std::cout << "=========" << std::endl;
}