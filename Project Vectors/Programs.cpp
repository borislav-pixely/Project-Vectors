#define endll endl << endl
#define NDEBUG

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
#include <assert.h>

using std::endl;
using std::cout;
using std::cin;

Element* element[3];

void error(char* errorMessage) {
	std::cerr << " ������: " << errorMessage << "! " << endll;
}

char get_answer() {
	char confirmation = 'n';
	cin >> confirmation;
	if (confirmation == 'y' || confirmation == 'Y')
		return 'y';
	else
		return 'n';
}

template <typename T>
char previous(int i = 0) {
	cout << " ������ �� �� ���������� ��������� ����� "
		 << dynamic_cast<T*>(element[i])->get_name() << "? (y/n): ";
	return get_answer();
}

char resumption() {
	cout << " ������ �� ���� ��������? (y/n): ";
	return get_answer();
}

char confirm_clear() {
	cout << " ������� �� ���, �� ������ �� ��������� ������ �������? (y/n): ";
	return get_answer();
}

void clear_console() {
	if (confirm_clear() == 'y')
		system("cls");
}

template <typename T>
void get_object(unsigned short count) {
	assert(3 >= count && count >= 1);
	for (int i = 0; i < count; i++) {
		if (element[i] == NULL) {
			if (count > 1)
				cout << " ����� � " << i + 1 << endl;
			element[i] = new T;
			cin >> *dynamic_cast<T*>(element[i]);
		} else if (previous<T>(i) == 'n') {
			if (count > 1)
				cout << " ����� � " << i + 1 << endl;
			element[i] = new T;
			cin >> *dynamic_cast<T*>(element[i]);
		}
	}
}

char exit() {
	if (resumption() == 'n') {
		for (int i = 0; i < sizeof(element) / sizeof(element[0]); i++) {
			if (element[i] != NULL) {
				delete[] element[i];
				element[i] = NULL;
			}
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

		case 0:
			return 0;
			
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

		case 0:
			return 0;

		default:
			error("��������� �����");
	}
	return exit();
}

char vector_program(int userInput, std::ostream& out) {
	switch (userInput) {
		case 1:	// ����������� �� ������� �� ������
			get_object<Vector>(1);
			out << endl << std::setprecision(4) << std::fixed
				<< " ������ " << 
				dynamic_cast<Vector*>(element[0])->get_name()
				<< " ��� ������� " << 
				dynamic_cast<Vector*>(element[0])->length() << endll;
			break;

		case 2: // ����������� �� ������ �� ������
			get_object<Vector>(1);
			out << endl << std::setprecision(4) << std::fixed
				<< " ������ " <<
				dynamic_cast<Vector*>(element[0])->get_name();
			try {
				out << dynamic_cast<Vector*>(element[0])->direction()
					 << endll;
			} catch (VectorLengthException e) {}			
			break;

		case 3: // �������� �� ������ ����� ���� ������
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed
				<< " ������ " <<
				dynamic_cast<Vector*>(element[0])->get_name()
				<< " ���������� ����� ������ " <<
				dynamic_cast<Vector*>(element[1])->get_name();
			try {
				out << dynamic_cast<Vector*>(element[0])->
						projection(*dynamic_cast<Vector*>(element[1])) << endll;
			} catch (VectorLengthException e) {}
			break;

		case 4: // �������� �� ����� ������
			get_object<Vector>(1);
			out << endl << std::setprecision(4) << std::fixed
				<< " �������� " <<
				dynamic_cast<Vector*>(element[0])->get_name();
			if (!dynamic_cast<Vector*>(element[0])->is_a_zero_vector())
				out << " �� ";
			out << "� ����� ������." << endll;
			break;

		case 5: // �������� �� ����������� �� ��� �������
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed
				<< " �������� " << dynamic_cast<Vector*>(element[0])->get_name();
			try {
				if (!dynamic_cast<Vector*>(element[0])->
					parallel_to(*dynamic_cast<Vector*>(element[1])))
					out << " �� ";
				out << "e ��������� �� ������� " 
					 << dynamic_cast<Vector*>(element[1])->get_name() << "." << endll;
			} catch (VectorLengthException e) {}
			break;
			
		case 6: // �������� �� ����������������� �� ��� �������
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed
				<< " �������� " << dynamic_cast<Vector*>(element[0])->get_name();
			try {
				if (!dynamic_cast<Vector*>(element[0])->
					perpendicular_to(*dynamic_cast<Vector*>(element[1])))
					out << " �� ";
				out << "e ��������������� �� ������� "
					<< dynamic_cast<Vector*>(element[1])->get_name() << "." << endll;
			} catch (VectorLengthException e) {}
			break;
			
		case 7: // �������� �� ��� �������
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed    << " "
				 << dynamic_cast<Vector*>(element[0])->get_name() << " + "
				 << dynamic_cast<Vector*>(element[1])->get_name() << " = "
				 << *dynamic_cast<Vector*>(element[0]) + *dynamic_cast<Vector*>(element[1]) << endll;		
			break;

		case 8: // ������� �� ��� �������
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed << " "
				<< dynamic_cast<Vector*>(element[0])->get_name() << " - "
				<< dynamic_cast<Vector*>(element[1])->get_name() << " = "
				<< *dynamic_cast<Vector*>(element[0]) - *dynamic_cast<Vector*>(element[1]) << endll;
			break;

		case 9: // ��������� �� ������ � ������ �����
			
			
		case 10: // �������� ������������ �� ��� �������
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed 
				 << " �������� ������������: "
				 << dynamic_cast<Vector*>(element[0])->get_name() << " * "
				 << dynamic_cast<Vector*>(element[1])->get_name() << " = "
				 << *dynamic_cast<Vector*>(element[0]) * *dynamic_cast<Vector*>(element[1]) << endll;
			break;
			
		case 11: // �������� ������������ �� ��� �������
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed
				<< dynamic_cast<Vector*>(element[0])->get_name() << " ^ "
				<< dynamic_cast<Vector*>(element[1])->get_name() << " = "
				<< (*dynamic_cast<Vector*>(element[0]) ^ *dynamic_cast<Vector*>(element[1])) << endll;
			break;
			
		case 12: // ������� ������������ �� ��� �������
			get_object<Vector>(3);
			out << endl << std::setprecision(4) << std::fixed
				<< " ������� ������������: ("
				<< dynamic_cast<Vector*>(element[0])->get_name() << " ^ "
				<< dynamic_cast<Vector*>(element[1])->get_name() << ") * "
				<< dynamic_cast<Vector*>(element[2])->get_name() << " = "
				<< dynamic_cast<Vector*>(element[0])->operator()
				 (*dynamic_cast<Vector*>(element[1]), *dynamic_cast<Vector*>(element[2])) << endll;
			break;
			
		case 0:
			return 0;

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

		case 0:
			return 0;
			
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

		case 0:
			return 0;
			
		default:
			error("��������� �����");
	}
	return exit();
}