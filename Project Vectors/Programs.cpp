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

Element* element[2];

void error(char* errorMessage) {
	std::cerr << " ������: " << errorMessage << "! " << endll;
}

char ask_for(const char* operation) {
	char confirmation = 'n';
	if (operation == "resumption")
		cout << " ������ �� ���� ��������? (y/n): ";
	else if (operation == "previous")
		cout << " ������ �� �� ���������� ���������� �����? (y/n): ";
	else if (operation == "clear")
		cout << " ������� �� ���, �� ������ �� ��������� ������ �������? (y/n): ";
	cin >> confirmation;
	if (confirmation == 'y' || confirmation == 'Y')
		return 'y';
	else
		return 'n';
}

void clear_console() {
	if (ask_for("clear") == 'y')
		system("cls");
}

template <typename T>
void get_object(unsigned short count) {
	if (element[0] == NULL) {
		if (count == 2) cout << " ����� � 1" << endl;
		element[0] = new T;
		cin >> *dynamic_cast<T*>(element[0]);
	} else if (ask_for("previous") == 'n') {
		element[0] = new T;
		cin >> *dynamic_cast<T*>(element[0]);
	}
	if (count == 2) {
		if (element[1] == NULL) {
			cout << " ����� � 2" << endl;
			element[1] = new T;
			cin >> *dynamic_cast<T*>(element[1]);
		} else if (ask_for("previous") == 'n') {
			element[1] = new T;
			cin >> *dynamic_cast<T*>(element[1]);
		}
	}
}

char exit() {
	if (ask_for("resumption") == 'n') {
		if (element[0] != NULL) {
			delete element[0];
			element[0] = NULL;
		}
		if (element[1] != NULL) {
			delete element[1];
			element[1] = NULL;
		}
		return 'n';
	} else {
		return 'y';
	}
}

char line_program(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			break;
			
		case 2:
			cout << " --CASE 2--" << endll;
			break;
			
		case 3:
			cout << " --CASE 3--" << endll;
			break;
			
		case 4:
			cout << " --CASE 4--" << endll;
			break;
			
		case 5:
			cout << " --CASE 5--" << endll;
			break;
			
		case 6:
			cout << " --CASE 6--" << endll;
			break;
			
		case 7:
			cout << " --CASE 7--" << endll;
			break;
			
		case 8:
			cout << " --CASE 8--" << endll;
			break;
			
		case 9:
			cout << " --CASE 9--" << endll;
			break;
			
		default:
			error("��������� �����");
	}
	return exit();
}

char point_program(int userInput) {
	switch (userInput) {
		case 1: // �������� ���� ������ ����� ������� � ����� �����
			get_object<Point>(2);
			cout << endl << std::setprecision(4) << std::fixed <<
				 " ����� " << dynamic_cast<Point*>(element[0])->get_name();
			if (*dynamic_cast<Point*>(element[0]) == *dynamic_cast<Point*>(element[1]))
				 cout << " ������� � ����� ";
			else
				 cout << " �� ������� � ����� ";
			cout << dynamic_cast<Point*>(element[1])->get_name() << "." << endll;
			break;

		default:
			error("��������� �����");
	}
	return exit();
}

char vector_program(int userInput) {
	switch (userInput) {
		case 1:	// ����������� �� ������� �� ������
			get_object<Vector>(1);
			cout << endl << std::setprecision(4) << std::fixed
				 << " ������ " << 
				 dynamic_cast<Vector*>(element[0])->get_name()
				 << " ��� ������� " << 
				 dynamic_cast<Vector*>(element[0])->length() << endll;
			break;

		case 2: // ����������� �� ������ �� ������
			get_object<Vector>(1);
			cout << endl << std::setprecision(4) << std::fixed
				 << " ������ " <<
				 dynamic_cast<Vector*>(element[0])->get_name();
			try {
				cout << dynamic_cast<Vector*>(element[0])->direction()
					 << endll;
			} catch (VectorLengthException e) {}			
			break;

		case 3: // �������� �� ������ ����� ���� ������
			get_object<Vector>(2);
			cout << endl << std::setprecision(4) << std::fixed
				 << " ������ " <<
				 dynamic_cast<Vector*>(element[0])->get_name()
				 << " ���������� ����� ������ " <<
				 dynamic_cast<Vector*>(element[1])->get_name();
			try {
				cout << dynamic_cast<Vector*>(element[0])->
						projection(*dynamic_cast<Vector*>(element[1])) << endll;
			} catch (VectorLengthException e) {}
			break;

		case 4: // �������� �� ����� ������
			get_object<Vector>(1);
			cout << endl << std::setprecision(4) << std::fixed
				 << " �������� " <<
				 dynamic_cast<Vector*>(element[0])->get_name();
			if (dynamic_cast<Vector*>(element[0])->is_a_zero_vector())
				cout << " � ����� ������." << endll;
			else
				cout << " �� � ����� ������." << endll;
			break;

		case 5:
			cout << " --CASE 5--" << endll;
			break;
			
		case 6:
			cout << " --CASE 6--" << endll;
			break;
			
		case 7:
			cout << " --CASE 7--" << endll;
			break;
			
		case 8: // ��������� �� ������ � ������ �����
			cout << " --CASE 8--" << endll;
			break;
			
		case 9:
			cout << " --CASE 9--" << endll;
			break;
			
		case 10:
			cout << " --CASE 10--" << endll;
			break;
			
		case 11:
			cout << " --CASE 11--" << endll;
			break;
			
		default:
			error("��������� �����");
	}
	return exit();
}

char segment_program(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			break;
			
		case 2:
			cout << " --CASE 2--" << endll;
			break;
			
		case 3:
			cout << " --CASE 3--" << endll;
			break;
			
		default:
			error("��������� �����");
	}
	return exit();
}

char triangle_program(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			break;
			
		case 2: // �������� �� ������ �� ����� ����������
			get_object<Triangle>(1);
			try {
				cout << endl << std::setprecision(4) << std::fixed
					 << " ������������ " <<
					 dynamic_cast<Triangle*>(element[0])->get_name()
					 << " ��� ���� " <<
				     dynamic_cast<Triangle*>(element[0])->area()
					 << "." << endl;
			} catch (EqualPointException e) {}				 
			break;
			
		case 3: // �������� �� ���������� �� ����� ����������
			get_object<Triangle>(1);
			try {
				cout << endl << std::setprecision(4) << std::fixed
				     << " ������������ " <<
					 dynamic_cast<Triangle*>(element[0])->get_name()
				     << " ��� ��������� " <<
					 dynamic_cast<Triangle*>(element[0])->perimiter() 
					 << "." << endl;
			} catch (EqualPointException e) {}
			break;
			
		case 4:
			cout << " --CASE 4--" << endll;
			break;
			
		default:
			error("��������� �����");
	}
	return exit();
}