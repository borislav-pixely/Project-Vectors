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
#include <string>
#include <ctime>

using std::endl;
using std::cout;
using std::cin;

Element* element[3];
bool timeAdded = false;
bool object1Added = false;
bool object2Added = false;
bool object3Added = false;

template <typename T>
void get_object(unsigned short, std::string = "Empty", bool = false);
void error(char*, char* = "");
char confirm_clear();
void clear_console();
char previous(int);
char get_answer();
char resumption();
char exit();

template <typename T>
void get_object(unsigned short count, std::string str, bool automatic) {
	if (!automatic) {
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
	} else {
		double value = 0.;
		for (int i = 0; i < count; i++) {
			if (element[i] == NULL)
				element[i] = new T;	
			for (int j = 0; j < 3; j++) {
				value = stod(str);
				if (j == 0) str.replace(str.begin(), str.begin() + 4, "");
				else str.replace(str.begin(), str.begin() + 5, "");
				*dynamic_cast<T*>(element[i]) << value;
			}
		}
	}
}

struct FileAndConsole : std::ofstream {
	FileAndConsole(const std::string& file) :
		std::ofstream(file, std::ios_base::app), file(file) {};
	const std::string file;
};

template <typename T>
FileAndConsole& operator << (FileAndConsole& fac, const T& text) {
	if (!timeAdded) {
		char buffer[80];
		timeAdded = true;
		time_t t = time(0);
		struct tm * now = localtime(&t);	
		strftime(buffer, 80, " ������ ����� � %H �. � %M ���.:", now);
		static_cast<std::ofstream&>(fac) << endl << buffer 
			<< endl << " -------------------------------" << endl;

	}
	if (!object1Added) {	
		if (element[0] != NULL) {
			object1Added = true;
			static_cast<std::ofstream&>(fac) << *dynamic_cast<Vector*>(element[0]) << endl;
		}			
	} else if (!object2Added) {	
		if (element[1] != NULL) {
			object2Added = true;
			static_cast<std::ofstream&>(fac) << *dynamic_cast<Vector*>(element[1]) << endl;
		}			
	} else if (!object3Added) {
		if (element[2] != NULL) {
			object3Added = true;
			static_cast<std::ofstream&>(fac) << *dynamic_cast<Vector*>(element[2]) << endl;
		}		
	} 
	static_cast<std::ofstream&>(fac) << text;
	cout << text;
	return fac;
}

char line_(unsigned short userInput, std::string in, bool automatic) {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Line-Output %d-%m-%Y.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1:	// �������� �� ������ �� �����
			if (automatic) get_object<Line>(1, in, true);
			else get_object<Line>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " ������� " <<
				dynamic_cast<Line*>(element[0])->get_name()
				<< " ��� ������ " <<
				dynamic_cast<Line*>(element[0])->direction() << "\n\n";
			break;
			
		case 2:	// �������� �� �������� ������ �� �����
			if (automatic) get_object<Line>(1, in, true);
			else get_object<Line>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " ������� " <<
				dynamic_cast<Line*>(element[0])->get_name()
				<< " ��� �������� ������ " <<
				dynamic_cast<Line*>(element[0])->normal_vector() << "\n\n";
			break;
			
		case 3:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;
			
		case 4:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;
			
		case 5:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;
			
		case 6:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;
			
		case 7:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;
			
		case 8:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;
			
		case 9:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;

		case 0:
			return 0;
			
		default:
			error("��������� �����");
	}
	if (automatic) return 0;
	else return exit();
}

char point_(unsigned short userInput, std::string in, bool automatic) {
	time_t t = time(0);
	struct tm* now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Point-Output %d-%m-%Y.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1: // �������� ���� ������ ����� ������� � ����� �����
			if (automatic) get_object<Point>(2, in, true);
			else get_object<Point>(2);
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
	if (automatic) return 0;
	else return exit();
}

char vector_(unsigned short userInput, std::string in, bool automatic) {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Vector-Output %d-%m-%Y.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1:	// ����������� �� ������� �� ������
			if (automatic) get_object<Vector>(1, in, true);
			else get_object<Vector>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " ������ " << 
				dynamic_cast<Vector*>(element[0])->get_name()
				<< " ��� ������� " << 
				dynamic_cast<Vector*>(element[0])->length() << "\n\n";
			break;

		case 2: // ����������� �� ������ �� ������
			if (automatic) get_object<Vector>(1, in, true);
			else get_object<Vector>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " ������ " <<
				dynamic_cast<Vector*>(element[0])->get_name();
			try {
				out << dynamic_cast<Vector*>(element[0])->direction()
					<< "\n\n";
			} catch (VectorLengthException e) {}
			break;

		case 3: // �������� �� ������ ����� ���� ������
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
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
			if (automatic) get_object<Vector>(1, in, true);
			else get_object<Vector>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " �������� " <<
				dynamic_cast<Vector*>(element[0])->get_name();
			if (!dynamic_cast<Vector*>(element[0])->is_a_zero_vector())
				out << " ��";
			out << " � ����� ������." << "\n\n";
			break;

		case 5: // �������� �� ����������� �� ��� �������
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " �������� " << dynamic_cast<Vector*>(element[0])->get_name();
			try {
				if (!dynamic_cast<Vector*>(element[0])->
					parallel_to(*dynamic_cast<Vector*>(element[1])))
					out << " ��";
				out << " e ��������� �� ������� " 
					 << dynamic_cast<Vector*>(element[1])->get_name() << "." << "\n\n";
			} catch (VectorLengthException e) {}
			break;
			
		case 6: // �������� �� ����������������� �� ��� �������
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " �������� " << dynamic_cast<Vector*>(element[0])->get_name();
			try {
				if (!dynamic_cast<Vector*>(element[0])->
					perpendicular_to(*dynamic_cast<Vector*>(element[1])))
					out << " ��";
				out << " e ��������������� �� ������� "
					<< dynamic_cast<Vector*>(element[1])->get_name() << "." << "\n\n";
			} catch (VectorLengthException e) {}
			break;
			
		case 7: // �������� �� ��� �������
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed    << " "
				 << dynamic_cast<Vector*>(element[0])->get_name() << " + "
				 << dynamic_cast<Vector*>(element[1])->get_name() << " = "
				 << *dynamic_cast<Vector*>(element[0]) + *dynamic_cast<Vector*>(element[1]) << "\n\n";		
			break;

		case 8: // ������� �� ��� �������
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed << " "
				<< dynamic_cast<Vector*>(element[0])->get_name() << " - "
				<< dynamic_cast<Vector*>(element[1])->get_name() << " = "
				<< *dynamic_cast<Vector*>(element[0]) - *dynamic_cast<Vector*>(element[1]) << "\n\n";
			break;

		case 9: { // ��������� �� ������ � ������ �����
			if (automatic) get_object<Vector>(1, in, true);
			else get_object<Vector>(1);
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
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed 
				 << " �������� ������������: "
				 << dynamic_cast<Vector*>(element[0])->get_name() << " * "
				 << dynamic_cast<Vector*>(element[1])->get_name() << " = "
				 << *dynamic_cast<Vector*>(element[0]) * *dynamic_cast<Vector*>(element[1]) << "\n\n";
			break;
			
		case 11: // �������� ������������ �� ��� �������
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< dynamic_cast<Vector*>(element[0])->get_name() << " ^ "
				<< dynamic_cast<Vector*>(element[1])->get_name() << " = "
				<< (*dynamic_cast<Vector*>(element[0]) ^ *dynamic_cast<Vector*>(element[1])) << "\n\n";
			break;
			
		case 12: // ������� ������������ �� ��� �������
			if (automatic) get_object<Vector>(3, in, true);
			else get_object<Vector>(3);
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
	if (automatic) return 0;
	else return exit();
}

char segment_(unsigned short userInput, std::string in, bool automatic) {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Segment-Output %d-%m-%Y.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;
			
		case 2:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;
			
		case 3:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;

		case 0:
			return 0;
			
		default:
			error("��������� �����");
	}
	if (automatic) return 0;
	else return exit();
}

char triangle_(unsigned short userInput, std::string in, bool automatic) {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Triangle-Output %d-%m-%Y.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;
			
		case 2: // �������� �� ������ �� ����� ����������
			if (automatic) get_object<Triangle>(1, in, true);
			else get_object<Triangle>(1);
			try {
				out << '\n' << std::setprecision(4) << std::fixed
					<< " ������������ " <<
					dynamic_cast<Triangle*>(element[0])->get_name()
					<< " ��� ���� " <<
					dynamic_cast<Triangle*>(element[0])->area() << '\n';
			} catch (EqualPointException e) {}				 
			break;
			
		case 3: // �������� �� ���������� �� ����� ����������
			if (automatic) get_object<Triangle>(1, in, true);
			else get_object<Triangle>(1);
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
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;

		case 0:
			return 0;
			
		default:
			error("��������� �����");
	}
	if (automatic) return 0;
	else return exit();
}


char tetrahedron_(unsigned short userInput, std::string in, bool automatic) {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "Triangle-Output %d-%m-%Y.txt", now);
	FileAndConsole out(buffer);
	if (!out) {
		error(buffer, " �� ���� �� ���� �������� � ���� ����������");
		return -1;
	}
	switch (userInput) {
		case 1:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;

		case 0:
			return 0;

		default:
			error("��������� �����");
	}
	if (automatic) return 0;
	else return exit();
}

void error(char* errorMessage, char* additionalInfo) {
	std::cerr << " ������: " << errorMessage << additionalInfo << "! \n\n";
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

void garbage_collector() {
	for (int i = 0; i < sizeof(element) / sizeof(element[0]); i++) {
		if (element[i] != NULL)
			delete[] element[i];
	}
}