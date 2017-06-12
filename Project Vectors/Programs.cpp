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
#include <assert.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using std::endl;
using std::cout;
using std::cin;

Element* element[3];

struct FileAndConsole : std::ofstream {
	FileAndConsole(const std::string& file) :
		std::ofstream(file, std::ios_base::app), file(file) {};
	const std::string file;
};

template <typename T>
FileAndConsole& operator << (FileAndConsole& fac, const T& text) {
	static_cast<std::ofstream&>(fac) << text;
	cout << text;
	return fac;
};

void error(char* errorMessage, char* additionalInfo = "") {
	std::cerr << " ������: " << errorMessage << additionalInfo << "! " << endll;
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
	time_t t = time(0);
	struct tm * now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Line-Output %d-%m-%Y %H.%M.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1:
			out << " --CASE 1--" << "\n\n";
			break;
			
		case 2:
			out << " --CASE 2--" << "\n\n";
			break;
			
		case 3:
			out << " --CASE 3--" << "\n\n";
			break;
			
		case 4:
			out << " --CASE 4--" << "\n\n";
			break;
			
		case 5:
			out << " --CASE 5--" << "\n\n";
			break;
			
		case 6:
			out << " --CASE 6--" << "\n\n";
			break;
			
		case 7:
			out << " --CASE 7--" << "\n\n";
			break;
			
		case 8:
			out << " --CASE 8--" << "\n\n";
			break;
			
		case 9:
			out << " --CASE 9--" << "\n\n";
			break;

		case 0:
			return 0;
			
		default:
			error("��������� �����");
	}
	return exit();
}

char point_program(int userInput) {
	time_t t = time(0);
	struct tm* now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Point-Output %d-%m-%Y %H.%M.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1: // �������� ���� ������ ����� ������� � ����� �����
			get_object<Point>(2);
			out << '\n' << std::setprecision(4) << std::fixed <<
				 " ����� " << dynamic_cast<Point*>(element[0])->get_name();
			if (*dynamic_cast<Point*>(element[0]) == *dynamic_cast<Point*>(element[1]))
				 out << " ������� � ����� ";
			else
				 out << " �� ������� � ����� ";
			out << dynamic_cast<Point*>(element[1])->get_name() << "." << "\n\n";
			break;

		case 0:
			return 0;

		default:
			error("��������� �����");
	}
	return exit();
}

char vector_program(int userInput) {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Vector-Output %d-%m-%Y %H.%M.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1:	// ����������� �� ������� �� ������
			get_object<Vector>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " ������ " << 
				dynamic_cast<Vector*>(element[0])->get_name()
				<< " ��� ������� " << 
				dynamic_cast<Vector*>(element[0])->length() << "\n\n";
			break;

		case 2: // ����������� �� ������ �� ������
			get_object<Vector>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " ������ " <<
				dynamic_cast<Vector*>(element[0])->get_name();
			try {
				out << dynamic_cast<Vector*>(element[0])->direction()
					<< "\n\n";
			} catch (VectorLengthException e) {}
			break;

		case 3: // �������� �� ������ ����� ���� ������
			get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " ������ " <<
				dynamic_cast<Vector*>(element[0])->get_name()
				<< " ���������� ����� ������ " <<
				dynamic_cast<Vector*>(element[1])->get_name();
			try {
				out << dynamic_cast<Vector*>(element[0])->
						projection(*dynamic_cast<Vector*>(element[1])) << "\n\n";
			} catch (VectorLengthException e) {}
			break;

		case 4: // �������� �� ����� ������
			get_object<Vector>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " �������� " <<
				dynamic_cast<Vector*>(element[0])->get_name();
			if (!dynamic_cast<Vector*>(element[0])->is_a_zero_vector())
				out << " �� ";
			out << "� ����� ������." << "\n\n";
			break;

		case 5: // �������� �� ����������� �� ��� �������
			get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " �������� " << dynamic_cast<Vector*>(element[0])->get_name();
			try {
				if (!dynamic_cast<Vector*>(element[0])->
					parallel_to(*dynamic_cast<Vector*>(element[1])))
					out << " �� ";
				out << "e ��������� �� ������� " 
					 << dynamic_cast<Vector*>(element[1])->get_name() << "." << "\n\n";
			} catch (VectorLengthException e) {}
			break;
			
		case 6: // �������� �� ����������������� �� ��� �������
			get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " �������� " << dynamic_cast<Vector*>(element[0])->get_name();
			try {
				if (!dynamic_cast<Vector*>(element[0])->
					perpendicular_to(*dynamic_cast<Vector*>(element[1])))
					out << " �� ";
				out << "e ��������������� �� ������� "
					<< dynamic_cast<Vector*>(element[1])->get_name() << "." << "\n\n";
			} catch (VectorLengthException e) {}
			break;
			
		case 7: // �������� �� ��� �������
			get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed    << " "
				 << dynamic_cast<Vector*>(element[0])->get_name() << " + "
				 << dynamic_cast<Vector*>(element[1])->get_name() << " = "
				 << *dynamic_cast<Vector*>(element[0]) + *dynamic_cast<Vector*>(element[1]) << "\n\n";		
			break;

		case 8: // ������� �� ��� �������
			get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed << " "
				<< dynamic_cast<Vector*>(element[0])->get_name() << " - "
				<< dynamic_cast<Vector*>(element[1])->get_name() << " = "
				<< *dynamic_cast<Vector*>(element[0]) - *dynamic_cast<Vector*>(element[1]) << "\n\n";
			break;

		case 9: { // ��������� �� ������ � ������ �����
			get_object<Vector>(1);
			double real = 0.;
			cout << " �������� ������ �����: ";
			cin >> real;
			out << '\n' << std::setprecision(4) << std::fixed
				<< " ��������� � ������ �����: "
				<< dynamic_cast<Vector*>(element[0])->get_name()
				<< " * " << real << " = "
				<< *dynamic_cast<Vector*>(element[0]) * real << "\n\n";
			break;
		}			
		case 10: // �������� ������������ �� ��� �������
			get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed 
				 << " �������� ������������: "
				 << dynamic_cast<Vector*>(element[0])->get_name() << " * "
				 << dynamic_cast<Vector*>(element[1])->get_name() << " = "
				 << *dynamic_cast<Vector*>(element[0]) * *dynamic_cast<Vector*>(element[1]) << "\n\n";
			break;
			
		case 11: // �������� ������������ �� ��� �������
			get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< dynamic_cast<Vector*>(element[0])->get_name() << " ^ "
				<< dynamic_cast<Vector*>(element[1])->get_name() << " = "
				<< (*dynamic_cast<Vector*>(element[0]) ^ *dynamic_cast<Vector*>(element[1])) << "\n\n";
			break;
			
		case 12: // ������� ������������ �� ��� �������
			get_object<Vector>(3);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " ������� ������������: ("
				<< dynamic_cast<Vector*>(element[0])->get_name() << " ^ "
				<< dynamic_cast<Vector*>(element[1])->get_name() << ") * "
				<< dynamic_cast<Vector*>(element[2])->get_name() << " = "
				<< dynamic_cast<Vector*>(element[0])->operator()
				 (*dynamic_cast<Vector*>(element[1]), *dynamic_cast<Vector*>(element[2])) << "\n\n";
			break;
			
		case 0:
			return 0;

		default:
			error("��������� �����");
	}
	return exit();
}

char segment_program(int userInput) {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Segment-Output %d-%m-%Y %H.%M.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1:
			out << " --CASE 1--" << "\n\n";
			break;
			
		case 2:
			out << " --CASE 2--" << "\n\n";
			break;
			
		case 3:
			out << " --CASE 3--" << "\n\n";
			break;

		case 0:
			return 0;
			
		default:
			error("��������� �����");
	}
	return exit();
}

char triangle_program(int userInput) {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Triangle-Output %d-%m-%Y %H.%M.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1:
			out << " --CASE 1--" << "\n\n";
			break;
			
		case 2: // �������� �� ������ �� ����� ����������
			get_object<Triangle>(1);
			try {
				out << '\n' << std::setprecision(4) << std::fixed
					<< " ������������ " <<
					dynamic_cast<Triangle*>(element[0])->get_name()
					<< " ��� ���� " <<
					dynamic_cast<Triangle*>(element[0])->area() << '\n';
			} catch (EqualPointException e) {}				 
			break;
			
		case 3: // �������� �� ���������� �� ����� ����������
			get_object<Triangle>(1);
			try {
				out << '\n' << std::setprecision(4) << std::fixed
				    << " ������������ " <<
					dynamic_cast<Triangle*>(element[0])->get_name()
				    << " ��� ��������� " <<
					dynamic_cast<Triangle*>(element[0])->perimiter() 
					<< "." << '\n';
			} catch (EqualPointException e) {}
			break;
			
		case 4:
			out << " --CASE 4--" << "\n\n";
			break;

		case 0:
			return 0;
			
		default:
			error("��������� �����");
	}
	return exit();
}