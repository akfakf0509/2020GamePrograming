#pragma once
#include <fstream>
#include <string>
#define DataMgr DataMager::instance()

using namespace std;

class DataMager
{
private:
	string name = "Player";
	int level = 37;
	int exp = 1000000;
public:
	DataMager();
	
	static DataMager* instance();

	int getLevel();
};

