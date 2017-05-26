#define endll endl << endl

#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int mainMenu() {
    unsigned short int userInput = 0;
	cout << " Моля, изберете вид геометричен обект:" << endl;
	cout << " -------------------------------------" << endll;
    cout << " 1 - Точка" << endl;
    cout << " 2 - Вектор" << endl;
    cout << " 3 - Линия" << endl;
    cout << " 4 - Отсечка" << endl;
    cout << " 5 - Триъгълник" << endl;
	cout << " 6 - Изчистване на конзолата" << endl;
    cout << " 0 - ИЗХОД" << endll;
    cout << " Вашият избор: ";
    cin >> userInput;
    cout << endl;
    return userInput;
}

int lineMenu() {
    unsigned short int userInput = 0;
    cout << " Моля, изберете операция за обекта:" << endl;
	cout << " ----------------------------------" << endll;
    cout << " 1 - намиране на посока на права" << endl;
    cout << " 2 - намиране на нормален вектор на права" << endl;
    cout << " 3 - намиране на ъгъл между две прави" << endl;
    cout << " 4 - проверка дали дадена точка лежи на дадена права" << endl;
    cout << " 5 - проверка дали дадена права е успоредна на друга права" << endl;
    cout << " 6 - проверка дали дадена права съвпада с друга права" << endl;
    cout << " 7 - проверка дали дадена права пресича друга права" << endl;
    cout << " 8 - проверка дали дадена права е кръстосана с друга права" << endl;
    cout << " 9 - проверка дали дадена права е перпендикулярна на друга права" << endl;
    cout << " 0 - ИЗХОД" << endll;
    cout << " Вашият избор: ";
    cin >> userInput;
    cout << endl;
    return userInput;
}

int pointMenu() {
	unsigned short int userInput = 0;
	cout << " Моля, изберете операция за обекта:" << endl;
	cout << " ----------------------------------" << endll;
	cout << " 1 - проверка дали дадена точка съвпада с друга точка" << endl;
	cout << " 0 - ИЗХОД" << endll;
	cout << " Вашият избор: ";
	cin >> userInput;
	cout << endl;
	return userInput;
}

int vectorMenu() {
    unsigned short int userInput = 0;
	cout << " Моля, изберете операция за обекта:" << endl;
	cout << " ----------------------------------" << endll;
    cout << " 1 - изчисляване на дължина на вектор" << endl;
    cout << " 2 - изчисляване на посока на вектор" << endl;
    cout << " 3 - проекция на вектор върху друг вектор" << endl;
    cout << " 4 - проверка за нулев вектор" << endl;
    cout << " 5 - проверка за успоредност на два вектора" << endl;
    cout << " 6 - проверка за перпендикулярност на два вектора" << endl;
    cout << " 7 - събиране на два вектора" << endl;
    cout << " 8 - умножение на вектор с реално число" << endl;
    cout << " 9 - скаларно произведение на два вектора" << endl;
    cout << " 10 - векторно произведение на два вектора" << endl;
    cout << " 11 - смесено произведение на три вектора" << endl;
    cout << " 0 - ИЗХОД" << endll;
    cout << " Вашият избор: ";
    cin >> userInput;
    cout << endl;
    return userInput;
}

int segmentMenu() {
    unsigned short int userInput = 0;
	cout << " Моля, изберете операция за обекта:" << endl;
	cout << " ----------------------------------" << endll;
    cout << " 1 - намиране на дължина на отсечка" << endl;
    cout << " 2 - намиране на среда на отсечка" << endl;
    cout << " 3 - проверка дали дадена точка лежи на дадена отсечка" << endl;
    cout << " 0 - ИЗХОД" << endll;
    cout << " Вашият избор: ";
    cin >> userInput;
    cout << endl;
    return userInput;
}

int triangleMenu() {
    unsigned short int userInput = 0;
    cout << " Моля, изберете операция за обекта:" << endl;
	cout << " ----------------------------------" << endll;
    cout << " 1 - определяне на вида на даден триъгълник" << endl;
    cout << " 2 - намиране на лицето на даден триъгълник" << endl;
    cout << " 3 - намиране на периметъра на даден триъгълник" << endl;
    cout << " 4 - намиране на медицентъра на даден триъгълник" << endl;
    cout << " 0 - ИЗХОД" << endll;
    cout << " Вашият избор: ";
    cin >> userInput;
    cout << endl;
    return userInput;
}
