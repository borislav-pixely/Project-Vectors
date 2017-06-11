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
	std::cerr << " Грешка: " << errorMessage << "! " << endll;
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

template <typename T>
void get_object(unsigned short count) {
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
			error("Невалиден избор");
	}
	return exit();
}

char point_program(int userInput) {
	switch (userInput) {
		case 1: // Проверка дали дадена точка съвпада с друга точка
			get_object<Point>(2);
			cout << endl << std::setprecision(4) << std::fixed <<
				 " Точка " << dynamic_cast<Point*>(element[0])->get_name();
			if (*dynamic_cast<Point*>(element[0]) == *dynamic_cast<Point*>(element[1]))
				 cout << " съвпада с точка ";
			else
				 cout << " не съвпада с точка ";
			cout << dynamic_cast<Point*>(element[1])->get_name() << "." << endll;
			break;

		case 0:
			return 0;

		default:
			error("Невалиден избор");
	}
	return exit();
}

char vector_program(int userInput, std::ostream& out) {
	switch (userInput) {
		case 1:	// Изчисляване на дължина на вектор
			get_object<Vector>(1);
			out << endl << std::setprecision(4) << std::fixed
				<< " Вектор " << 
				dynamic_cast<Vector*>(element[0])->get_name()
				<< " има дължина " << 
				dynamic_cast<Vector*>(element[0])->length() << endll;
			break;

		case 2: // Изчисляване на посока на вектор
			get_object<Vector>(1);
			out << endl << std::setprecision(4) << std::fixed
				<< " Вектор " <<
				dynamic_cast<Vector*>(element[0])->get_name();
			try {
				out << dynamic_cast<Vector*>(element[0])->direction()
					 << endll;
			} catch (VectorLengthException e) {}			
			break;

		case 3: // Проекция на вектор върху друг вектор
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed
				<< " Вектор " <<
				dynamic_cast<Vector*>(element[0])->get_name()
				<< " проектиран върху вектор " <<
				dynamic_cast<Vector*>(element[1])->get_name();
			try {
				out << dynamic_cast<Vector*>(element[0])->
						projection(*dynamic_cast<Vector*>(element[1])) << endll;
			} catch (VectorLengthException e) {}
			break;

		case 4: // Проверка за нулев вектор
			get_object<Vector>(1);
			out << endl << std::setprecision(4) << std::fixed
				<< " Векторът " <<
				dynamic_cast<Vector*>(element[0])->get_name();
			if (!dynamic_cast<Vector*>(element[0])->is_a_zero_vector())
				out << " не ";
			out << "е нулев вектор." << endll;
			break;

		case 5: // Проверка за успоредност на два вектора
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed
				<< " Векторът " << dynamic_cast<Vector*>(element[0])->get_name();
			try {
				if (!dynamic_cast<Vector*>(element[0])->
					parallel_to(*dynamic_cast<Vector*>(element[1])))
					out << " не ";
				out << "e успореден на вектора " 
					 << dynamic_cast<Vector*>(element[1])->get_name() << "." << endll;
			} catch (VectorLengthException e) {}
			break;
			
		case 6: // Проверка за перпендикулярност на два вектора
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed
				<< " Векторът " << dynamic_cast<Vector*>(element[0])->get_name();
			try {
				if (!dynamic_cast<Vector*>(element[0])->
					perpendicular_to(*dynamic_cast<Vector*>(element[1])))
					out << " не ";
				out << "e перпендикулярен на вектора "
					<< dynamic_cast<Vector*>(element[1])->get_name() << "." << endll;
			} catch (VectorLengthException e) {}
			break;
			
		case 7: // Събиране на два вектора
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed    << " "
				 << dynamic_cast<Vector*>(element[0])->get_name() << " + "
				 << dynamic_cast<Vector*>(element[1])->get_name() << " = "
				 << *dynamic_cast<Vector*>(element[0]) + *dynamic_cast<Vector*>(element[1]) << endll;		
			break;

		case 8: // Разлика на два вектора
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed << " "
				<< dynamic_cast<Vector*>(element[0])->get_name() << " - "
				<< dynamic_cast<Vector*>(element[1])->get_name() << " = "
				<< *dynamic_cast<Vector*>(element[0]) - *dynamic_cast<Vector*>(element[1]) << endll;
			break;

		case 9: // Умножение на вектор с реално число
			
			
		case 10: // Скаларно произведение на два вектора
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed 
				 << " Скаларно произведение: "
				 << dynamic_cast<Vector*>(element[0])->get_name() << " * "
				 << dynamic_cast<Vector*>(element[1])->get_name() << " = "
				 << *dynamic_cast<Vector*>(element[0]) * *dynamic_cast<Vector*>(element[1]) << endll;
			break;
			
		case 11: // Векторно произведение на два вектора
			get_object<Vector>(2);
			out << endl << std::setprecision(4) << std::fixed
				<< dynamic_cast<Vector*>(element[0])->get_name() << " ^ "
				<< dynamic_cast<Vector*>(element[1])->get_name() << " = "
				<< (*dynamic_cast<Vector*>(element[0]) ^ *dynamic_cast<Vector*>(element[1])) << endll;
			break;
			
		case 12: // Смесено произведение на три вектора
			get_object<Vector>(3);
			out << endl << std::setprecision(4) << std::fixed
				<< " Смесено произведение: ("
				<< dynamic_cast<Vector*>(element[0])->get_name() << " ^ "
				<< dynamic_cast<Vector*>(element[1])->get_name() << ") * "
				<< dynamic_cast<Vector*>(element[2])->get_name() << " = "
				<< dynamic_cast<Vector*>(element[0])->operator()
				 (*dynamic_cast<Vector*>(element[1]), *dynamic_cast<Vector*>(element[2])) << endll;
			break;
			
		case 0:
			return 0;

		default:
			error("Невалиден избор");
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
			error("Невалиден избор");
	}
	return exit();
}

char triangle_program(int userInput) {
	switch (userInput) {
		case 1:
			cout << " --CASE 1--" << endll;
			break;
			
		case 2: // намиране на лицето на даден триъгълник
			get_object<Triangle>(1);
			try {
				cout << endl << std::setprecision(4) << std::fixed
					 << " Триъгълникът " <<
					 dynamic_cast<Triangle*>(element[0])->get_name()
					 << " има лице " <<
				     dynamic_cast<Triangle*>(element[0])->area()
					 << "." << endl;
			} catch (EqualPointException e) {}				 
			break;
			
		case 3: // намиране на периметъра на даден триъгълник
			get_object<Triangle>(1);
			try {
				cout << endl << std::setprecision(4) << std::fixed
				     << " Триъгълникът " <<
					 dynamic_cast<Triangle*>(element[0])->get_name()
				     << " има периметър " <<
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
			error("Невалиден избор");
	}
	return exit();
}