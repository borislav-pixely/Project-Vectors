#define endll endl << endl

#include "VectorLengthException.h"
#include "EqualPointException.h"
#include "Triangle.h"
#include "Element.h"
#include "Segment.h"
#include "Vector.h"
#include "Point.h"
#include "Line.h"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

void error(char* errorMessage) {
	std::cerr << " ! ГРЕШКА: " << errorMessage << " ! " << endll;
}

char resumption() {
	char resumption = 'n';
	cout << " Искате ли нова операция? (y/n): ";
	cin >> resumption;
	cout << endl;
	if (resumption == 'y' || resumption == 'Y')
		return 'y';
	else
		return 'n';
}

void clearConsole() {
	char confirmation;
	cout << " Сигурни ли сте, че искате да изчистите цялата история? (y/n): ";
	cin >> confirmation;
	cout << endl;
	if (confirmation == 'y' || confirmation == 'Y')
		system("cls");
	else if (confirmation != 'n' && confirmation != 'N')
		error("Невалиден избор");
}

char runLineProgram(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			return resumption();
			break;
		case 2:
			cout << " --CASE 2--" << endll;
			return resumption();
			break;
		case 3:
			cout << " --CASE 3--" << endll;
			return resumption();
			break;
		case 4:
			cout << " --CASE 4--" << endll;
			return resumption();
			break;
		case 5:
			cout << " --CASE 5--" << endll;
			return resumption();
			break;
		case 6:
			cout << " --CASE 6--" << endll;
			return resumption();
			break;
		case 7:
			cout << " --CASE 7--" << endll;
			return resumption();
			break;
		case 8:
			cout << " --CASE 8--" << endll;
			return resumption();
			break;
		case 9:
			cout << " --CASE 9--" << endll;
			return resumption();
			break;
		case 0:
			return 'n';
			break;
		default:
			error("Невалиден избор");
	}
	return resumption();
}

char runPointProgram(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			return resumption();
			break;
		case 0:
			return 'n';
			break;
		default:
			error("Невалиден избор");
	}
	return resumption();
}

char runVectorProgram(int userInput) {
	switch (userInput) {
		case 1:
			// Изчисляване на дължина на вектор
			cout << " --CASE 1--" << endll;
			return resumption();
			break;
		case 2:
			cout << " --CASE 2--" << endll;
			return resumption();
			break;
		case 3:
			cout << " --CASE 3--" << endll;
			return resumption();
			break;
		case 4:
			cout << " --CASE 4--" << endll;
			return resumption();
			break;
		case 5:
			cout << " --CASE 5--" << endll;
			return resumption();
			break;
		case 6:
			cout << " --CASE 6--" << endll;
			return resumption();
			break;
		case 7:
			cout << " --CASE 7--" << endll;
			return resumption();
			break;
		case 8:
			// Умножение на вектор с реално число
			cout << " --CASE 8--" << endll;
			return resumption();
			break;
		case 9:
			cout << " --CASE 9--" << endll;
			return resumption();
			break;
		case 10:
			cout << " --CASE 10--" << endll;
			return resumption();
			break;
		case 11:
			cout << " --CASE 11--" << endll;
			return resumption();
			break;
		case 0:
			return 'n';
			break;
		default:
			error("Невалиден избор");
	}
	return resumption();
}

char runSegmentProgram(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			return resumption();
			break;
		case 2:
			cout << " --CASE 2--" << endll;
			return resumption();
			break;
		case 3:
			cout << " --CASE 3--" << endll;
			return resumption();
			break;
		case 0:
			return 'n';
			break;
		default:
			error("Невалиден избор");
	}
	return resumption();
}

char runTriangleProgram(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			return resumption();
			break;
		case 2:
			cout << " --CASE 2--" << endll;
			return resumption();
			break;
		case 3:
			cout << " --CASE 3--" << endll;
			return resumption();
			break;
		case 4:
			cout << " --CASE 4--" << endll;
			return resumption();
			break;
		case 0:
			return 'n';
			break;
		default:
			error("Невалиден избор");
	}
	return resumption();
}