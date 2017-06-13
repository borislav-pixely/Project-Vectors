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
					cout << " Обект № " << i + 1 << endl;
				element[i] = new T;
				cin >> *dynamic_cast<T*>(element[i]);
			} else if (previous<T>(i) == 'n') {
				if (count > 1)
					cout << " Обект № " << i + 1 << endl;
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
		strftime(buffer, 80, " Вашите данни в %H ч. и %M мин.:", now);
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
		error(buffer, " не може да бъде създаден в тази директория");
		return -1;
	}
	switch (userInput) {
		case 1:	// Намиране на посока на права
			if (automatic) get_object<Line>(1, in, true);
			else get_object<Line>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " Правата " <<
				dynamic_cast<Line*>(element[0])->get_name()
				<< " има посока " <<
				dynamic_cast<Line*>(element[0])->direction() << "\n\n";
			break;
			
		case 2:	// Намиране на нормален вектор на права
			if (automatic) get_object<Line>(1, in, true);
			else get_object<Line>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " Правата " <<
				dynamic_cast<Line*>(element[0])->get_name()
				<< " има нормален вектор " <<
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
			error("Невалиден избор");
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
		error(buffer, " не може да бъде създаден в тази директория");
		return -1;
	}
	switch (userInput) {
		case 1: // Проверка дали дадена точка съвпада с друга точка
			if (automatic) get_object<Point>(2, in, true);
			else get_object<Point>(2);
			out << '\n' << std::setprecision(4) << std::fixed <<
				 " Точка " << dynamic_cast<Point*>(element[0])->get_name();
			if (*dynamic_cast<Point*>(element[0]) == *dynamic_cast<Point*>(element[1]))
				 out << " съвпада с точка ";
			else
				 out << " не съвпада с точка ";
			out << dynamic_cast<Point*>(element[1])->get_name() << "." << "\n\n";
			break;

		case 0:
			return 0;

		default:
			error("Невалиден избор");
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
		error(buffer, " не може да бъде създаден в тази директория");
		return -1;
	}
	switch (userInput) {
		case 1:	// Изчисляване на дължина на вектор
			if (automatic) get_object<Vector>(1, in, true);
			else get_object<Vector>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " Вектор " << 
				dynamic_cast<Vector*>(element[0])->get_name()
				<< " има дължина " << 
				dynamic_cast<Vector*>(element[0])->length() << "\n\n";
			break;

		case 2: // Изчисляване на посока на вектор
			if (automatic) get_object<Vector>(1, in, true);
			else get_object<Vector>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " Вектор " <<
				dynamic_cast<Vector*>(element[0])->get_name();
			try {
				out << dynamic_cast<Vector*>(element[0])->direction()
					<< "\n\n";
			} catch (VectorLengthException e) {}
			break;

		case 3: // Проекция на вектор върху друг вектор
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " Вектор " <<
				dynamic_cast<Vector*>(element[0])->get_name()
				<< " проектиран върху вектор " <<
				dynamic_cast<Vector*>(element[1])->get_name();
			try {
				out << dynamic_cast<Vector*>(element[0])->
						projection(*dynamic_cast<Vector*>(element[1])) << "\n\n";
			} catch (VectorLengthException e) {}
			break;

		case 4: // Проверка за нулев вектор
			if (automatic) get_object<Vector>(1, in, true);
			else get_object<Vector>(1);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " Векторът " <<
				dynamic_cast<Vector*>(element[0])->get_name();
			if (!dynamic_cast<Vector*>(element[0])->is_a_zero_vector())
				out << " не";
			out << " е нулев вектор." << "\n\n";
			break;

		case 5: // Проверка за успоредност на два вектора
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " Векторът " << dynamic_cast<Vector*>(element[0])->get_name();
			try {
				if (!dynamic_cast<Vector*>(element[0])->
					parallel_to(*dynamic_cast<Vector*>(element[1])))
					out << " не";
				out << " e успореден на вектора " 
					 << dynamic_cast<Vector*>(element[1])->get_name() << "." << "\n\n";
			} catch (VectorLengthException e) {}
			break;
			
		case 6: // Проверка за перпендикулярност на два вектора
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " Векторът " << dynamic_cast<Vector*>(element[0])->get_name();
			try {
				if (!dynamic_cast<Vector*>(element[0])->
					perpendicular_to(*dynamic_cast<Vector*>(element[1])))
					out << " не";
				out << " e перпендикулярен на вектора "
					<< dynamic_cast<Vector*>(element[1])->get_name() << "." << "\n\n";
			} catch (VectorLengthException e) {}
			break;
			
		case 7: // Събиране на два вектора
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed    << " "
				 << dynamic_cast<Vector*>(element[0])->get_name() << " + "
				 << dynamic_cast<Vector*>(element[1])->get_name() << " = "
				 << *dynamic_cast<Vector*>(element[0]) + *dynamic_cast<Vector*>(element[1]) << "\n\n";		
			break;

		case 8: // Разлика на два вектора
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed << " "
				<< dynamic_cast<Vector*>(element[0])->get_name() << " - "
				<< dynamic_cast<Vector*>(element[1])->get_name() << " = "
				<< *dynamic_cast<Vector*>(element[0]) - *dynamic_cast<Vector*>(element[1]) << "\n\n";
			break;

		case 9: { // Умножение на вектор с реално число
			if (automatic) get_object<Vector>(1, in, true);
			else get_object<Vector>(1);
			double real = 0.;
			cout << " Въведете реално число: ";
			cin >> real;
			out << '\n' << std::setprecision(4) << std::fixed
				<< " Умножение с реално число: "
				<< dynamic_cast<Vector*>(element[0])->get_name()
				<< " * " << real << " = "
				<< *dynamic_cast<Vector*>(element[0]) * real << "\n\n";
			break;
		}			
		case 10: // Скаларно произведение на два вектора
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed 
				 << " Скаларно произведение: "
				 << dynamic_cast<Vector*>(element[0])->get_name() << " * "
				 << dynamic_cast<Vector*>(element[1])->get_name() << " = "
				 << *dynamic_cast<Vector*>(element[0]) * *dynamic_cast<Vector*>(element[1]) << "\n\n";
			break;
			
		case 11: // Векторно произведение на два вектора
			if (automatic) get_object<Vector>(2, in, true);
			else get_object<Vector>(2);
			out << '\n' << std::setprecision(4) << std::fixed
				<< dynamic_cast<Vector*>(element[0])->get_name() << " ^ "
				<< dynamic_cast<Vector*>(element[1])->get_name() << " = "
				<< (*dynamic_cast<Vector*>(element[0]) ^ *dynamic_cast<Vector*>(element[1])) << "\n\n";
			break;
			
		case 12: // Смесено произведение на три вектора
			if (automatic) get_object<Vector>(3, in, true);
			else get_object<Vector>(3);
			out << '\n' << std::setprecision(4) << std::fixed
				<< " Смесено произведение: ("
				<< dynamic_cast<Vector*>(element[0])->get_name() << " ^ "
				<< dynamic_cast<Vector*>(element[1])->get_name() << ") * "
				<< dynamic_cast<Vector*>(element[2])->get_name() << " = "
				<< dynamic_cast<Vector*>(element[0])->operator()
				 (*dynamic_cast<Vector*>(element[1]), *dynamic_cast<Vector*>(element[2])) << "\n\n";
			break;
			
		case 0:
			return 0;

		default:
			error("Невалиден избор");
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
		error(buffer, " не може да бъде създаден в тази директория");
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
			error("Невалиден избор");
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
		error(buffer, " не може да бъде създаден в тази директория");
		return -1;
	}
	switch (userInput) {
		case 1:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;
			
		case 2: // намиране на лицето на даден триъгълник
			if (automatic) get_object<Triangle>(1, in, true);
			else get_object<Triangle>(1);
			try {
				out << '\n' << std::setprecision(4) << std::fixed
					<< " Триъгълникът " <<
					dynamic_cast<Triangle*>(element[0])->get_name()
					<< " има лице " <<
					dynamic_cast<Triangle*>(element[0])->area() << '\n';
			} catch (EqualPointException e) {}				 
			break;
			
		case 3: // намиране на периметъра на даден триъгълник
			if (automatic) get_object<Triangle>(1, in, true);
			else get_object<Triangle>(1);
			try {
				out << '\n' << std::setprecision(4) << std::fixed
				    << " Триъгълникът " <<
					dynamic_cast<Triangle*>(element[0])->get_name()
				    << " има периметър " <<
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
			error("Невалиден избор");
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
		error(buffer, " не може да бъде създаден в тази директория");
		return -1;
	}
	switch (userInput) {
		case 1:
			out << " This feature is not yet available. Please contact customer support." << "\n\n";
			break;

		case 0:
			return 0;

		default:
			error("Невалиден избор");
	}
	if (automatic) return 0;
	else return exit();
}

void error(char* errorMessage, char* additionalInfo) {
	std::cerr << " Грешка: " << errorMessage << additionalInfo << "! \n\n";
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
	cout << " Искате ли да използвате предишния обект "
		<< dynamic_cast<T*>(element[i])->get_name() << "? (y/n): ";
	return get_answer();
}

char resumption() {
	cout << " Искате ли нова операция? (y/n): ";
	return get_answer();
}

char confirm_clear() {
	cout << " Сигурни ли сте, че искате да изчистите цялата история? (y/n): ";
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