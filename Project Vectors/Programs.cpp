#include "VectorLengthException.h"
#include "EqualPointException.h"
#include "SafeInput.h"
#include "Triangle.h"
#include "Element.h"
#include "Segment.h"
#include "Vector.h"
#include "Point.h"
#include "Line.h"
#include <iomanip>
#include <iostream>
#define endll endl << endl

using std::endl;
using std::cout;
using std::cin;

Element* element;

void error(char* errorMessage) {
	std::cerr << " ! ������: " << errorMessage << " ! " << endll;
}

char resumption() {
	char resumption = 'n';
	cout << " ������ �� ���� ��������? (y/n): ";
	cin >> resumption;
	cout << endl;
	if (resumption == 'y' || resumption == 'Y')
		return 'y';
	else
		return 'n';
}

void clear_console() {
	char confirmation;
	cout << " ������� �� ���, �� ������ �� ��������� ������ �������? (y/n): ";
	cin >> confirmation;
	cout << endl;
	if (confirmation == 'y' || confirmation == 'Y')
		system("cls");
	else if (confirmation != 'n' && confirmation != 'N')
		error("��������� �����");
}

char line_program(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			return resumption();
			
		case 2:
			cout << " --CASE 2--" << endll;
			return resumption();
			
		case 3:
			cout << " --CASE 3--" << endll;
			return resumption();
			
		case 4:
			cout << " --CASE 4--" << endll;
			return resumption();
			
		case 5:
			cout << " --CASE 5--" << endll;
			return resumption();
			
		case 6:
			cout << " --CASE 6--" << endll;
			return resumption();
			
		case 7:
			cout << " --CASE 7--" << endll;
			return resumption();
			
		case 8:
			cout << " --CASE 8--" << endll;
			return resumption();
			
		case 9:
			cout << " --CASE 9--" << endll;
			return resumption();
			
		case 0:
			return 'n';
			
		default:
			error("��������� �����");
	}
	return resumption();
}

char point_program(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			return resumption();
			
		case 0:
			return 'n';
			
		default:
			error("��������� �����");
	}
	return resumption();
}

char vector_program(int userInput) {
	switch (userInput) {
		case 1:
		{	// ����������� �� ������� �� ������
			Vector A;
			cin >> A;
			cout << std::setprecision(4) << std::fixed
				 << " ������ " << A.get_name()
				 << " ��� ������� " << A.length() << endll;
			return resumption();
		}
		case 2:
		{	// ����������� �� ������ �� ������
			Vector A;
			cin >> A;
			cout << std::setprecision(4) << std::fixed
				 << " ������ " << A.get_name()
				 << " ��� ������ " << A.direction() << endll;
			return resumption();
		}
		case 3:
		{	// �������� �� ������ ����� ���� ������

			cout << "Not finished";
			return resumption();
		}
		case 4:
			cout << " --CASE 4--" << endll;
			return resumption();
		case 5:
			cout << " --CASE 5--" << endll;
			return resumption();
			;
		case 6:
			cout << " --CASE 6--" << endll;
			return resumption();
			
		case 7:
			cout << " --CASE 7--" << endll;
			return resumption();
			
		case 8:
			// ��������� �� ������ � ������ �����
			cout << " --CASE 8--" << endll;
			return resumption();
			
		case 9:
			cout << " --CASE 9--" << endll;
			return resumption();
			
		case 10:
			cout << " --CASE 10--" << endll;
			return resumption();
			
		case 11:
			cout << " --CASE 11--" << endll;
			return resumption();
			
		case 0:
			return 'n';
				
		default:
			error("��������� �����");
	}
	return resumption();
}

char segment_program(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			return resumption();
			
		case 2:
			cout << " --CASE 2--" << endll;
			return resumption();
			
		case 3:
			cout << " --CASE 3--" << endll;
			return resumption();
			
		case 0:
			return 'n';
			
		default:
			error("��������� �����");
	}
	return resumption();
}

char triangle_program(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			return resumption();
			
		case 2:
			cout << " --CASE 2--" << endll;
			return resumption();
			
		case 3:
			cout << " --CASE 3--" << endll;
			return resumption();
			
		case 4:
			cout << " --CASE 4--" << endll;
			return resumption();
			
		case 0:
			return 'n';
			
		default:
			error("��������� �����");
	}
	return resumption();
}