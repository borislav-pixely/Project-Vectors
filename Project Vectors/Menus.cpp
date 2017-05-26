#define endll endl << endl

#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int mainMenu() {
    unsigned short int userInput = 0;
	cout << " ����, �������� ��� ����������� �����:" << endl;
	cout << " -------------------------------------" << endll;
    cout << " 1 - �����" << endl;
    cout << " 2 - ������" << endl;
    cout << " 3 - �����" << endl;
    cout << " 4 - �������" << endl;
    cout << " 5 - ����������" << endl;
	cout << " 6 - ���������� �� ���������" << endl;
    cout << " 0 - �����" << endll;
    cout << " ������ �����: ";
    cin >> userInput;
    cout << endl;
    return userInput;
}

int lineMenu() {
    unsigned short int userInput = 0;
    cout << " ����, �������� �������� �� ������:" << endl;
	cout << " ----------------------------------" << endll;
    cout << " 1 - �������� �� ������ �� �����" << endl;
    cout << " 2 - �������� �� �������� ������ �� �����" << endl;
    cout << " 3 - �������� �� ���� ����� ��� �����" << endl;
    cout << " 4 - �������� ���� ������ ����� ���� �� ������ �����" << endl;
    cout << " 5 - �������� ���� ������ ����� � ��������� �� ����� �����" << endl;
    cout << " 6 - �������� ���� ������ ����� ������� � ����� �����" << endl;
    cout << " 7 - �������� ���� ������ ����� ������� ����� �����" << endl;
    cout << " 8 - �������� ���� ������ ����� � ���������� � ����� �����" << endl;
    cout << " 9 - �������� ���� ������ ����� � ��������������� �� ����� �����" << endl;
    cout << " 0 - �����" << endll;
    cout << " ������ �����: ";
    cin >> userInput;
    cout << endl;
    return userInput;
}

int pointMenu() {
	unsigned short int userInput = 0;
	cout << " ����, �������� �������� �� ������:" << endl;
	cout << " ----------------------------------" << endll;
	cout << " 1 - �������� ���� ������ ����� ������� � ����� �����" << endl;
	cout << " 0 - �����" << endll;
	cout << " ������ �����: ";
	cin >> userInput;
	cout << endl;
	return userInput;
}

int vectorMenu() {
    unsigned short int userInput = 0;
	cout << " ����, �������� �������� �� ������:" << endl;
	cout << " ----------------------------------" << endll;
    cout << " 1 - ����������� �� ������� �� ������" << endl;
    cout << " 2 - ����������� �� ������ �� ������" << endl;
    cout << " 3 - �������� �� ������ ����� ���� ������" << endl;
    cout << " 4 - �������� �� ����� ������" << endl;
    cout << " 5 - �������� �� ����������� �� ��� �������" << endl;
    cout << " 6 - �������� �� ����������������� �� ��� �������" << endl;
    cout << " 7 - �������� �� ��� �������" << endl;
    cout << " 8 - ��������� �� ������ � ������ �����" << endl;
    cout << " 9 - �������� ������������ �� ��� �������" << endl;
    cout << " 10 - �������� ������������ �� ��� �������" << endl;
    cout << " 11 - ������� ������������ �� ��� �������" << endl;
    cout << " 0 - �����" << endll;
    cout << " ������ �����: ";
    cin >> userInput;
    cout << endl;
    return userInput;
}

int segmentMenu() {
    unsigned short int userInput = 0;
	cout << " ����, �������� �������� �� ������:" << endl;
	cout << " ----------------------------------" << endll;
    cout << " 1 - �������� �� ������� �� �������" << endl;
    cout << " 2 - �������� �� ����� �� �������" << endl;
    cout << " 3 - �������� ���� ������ ����� ���� �� ������ �������" << endl;
    cout << " 0 - �����" << endll;
    cout << " ������ �����: ";
    cin >> userInput;
    cout << endl;
    return userInput;
}

int triangleMenu() {
    unsigned short int userInput = 0;
    cout << " ����, �������� �������� �� ������:" << endl;
	cout << " ----------------------------------" << endll;
    cout << " 1 - ���������� �� ���� �� ����� ����������" << endl;
    cout << " 2 - �������� �� ������ �� ����� ����������" << endl;
    cout << " 3 - �������� �� ���������� �� ����� ����������" << endl;
    cout << " 4 - �������� �� ����������� �� ����� ����������" << endl;
    cout << " 0 - �����" << endll;
    cout << " ������ �����: ";
    cin >> userInput;
    cout << endl;
    return userInput;
}
