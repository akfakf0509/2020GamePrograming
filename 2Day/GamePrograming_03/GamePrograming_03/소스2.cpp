#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

bool getStu(std::ifstream&, int&, int&, int&, int&);
void calcGrade(int, int, int, int&, char&);
void writeStu(std::ofstream&, int, int, char);

int main() {
	std::ifstream stuFile;
	stuFile.open("ch7STUFL.DAT");

	std::cout << "Start Program" << std::endl;

	if (!stuFile) {
		std::cerr << "FIle Open errer" << std::endl;
		exit(100);
	}

	std::ofstream gradesFile;
	gradesFile.open("ch7STUGR.DAT");

	if (!gradesFile) {
		std::cerr << "File Open errer" << std::endl;
		exit(100);
	}

	int stuId, exam1, exam2, finalExam, avrg;
	char grade;

	while (getStu(stuFile, stuId, exam1, exam2, finalExam)) {
		calcGrade(exam1, exam2, finalExam, avrg, grade);
		writeStu(gradesFile, stuId, avrg, grade);
	}

	stuFile.close();
	gradesFile.close();

	std::cout << "End Program" << std::endl;

	return 0;
}

bool getStu(std::ifstream& stuFile, int& stuId, int& exam1, int& exam2, int& finalexam) {
	stuFile >> stuId >> exam1 >> exam2 >> finalexam;
	return !!stuFile;
}

void calcGrade(int exam1, int exam2, int finalExam, int& avrg, char& grade) {
	avrg = (exam1 + exam2 + finalExam) / 3;

	if (avrg >= 90) {
		grade = 'A';
	}
	else if (avrg >= 80) {
		grade = 'B';
	}
	else if (avrg >= 70) {
		grade = 'C';
	}
	else if (avrg >= 70) {
		grade = 'D';
	}
	else {
		grade = 'F';
	}
}

void writeStu(std::ofstream& gradesFile, int stuId, int avrg, char grade) {
	gradesFile.fill(0);
	gradesFile << std::setw(4) << stuId;
	gradesFile.fill(' ');
	gradesFile << std::setw(3) << avrg;
	gradesFile << ' ' << grade << std::endl;
}