#pragma once
#include <iostream>
class Car
{
	int speed;
	int gear;
	std::string pcolor;

public:
	Car(int, int, std::string);

	int getSpeed();
	int getGear();
	std::string getPcolor();

	void setSpeed(int);
	void setGear(int);
	void setPcolor(std::string);

	void speedUp();
	void speedDown();
	void show();
};

