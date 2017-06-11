#include <clocale>
#include <fstream>
#include <cstdio>
#include <iostream>
#define objects menu("main")
#define Clear clear_console();
#define Exit running = false;
#define Error error("Невалиден избор");
#define Line while (line_program(menu("line")) == 'y') {}
#define Point while (point_program(menu("point")) == 'y') {}
#define Vector while (vector_program(menu("vector")) == 'y') {}
#define Segment while (segment_program(menu("segment")) == 'y') {}
#define Triangle while (triangle_program(menu("triangle")) == 'y') {}

std::ofstream file("test.txt");

int menu(char*);
char line_program(int);
char point_program(int);
char vector_program(int, std::ostream& = std::cout);
char segment_program(int);
char triangle_program(int);
void clear_console();
void error(char*);

int main(int argc, const char* argv[]) {

    std::setlocale(LC_ALL, "bulgarian");
	bool running = true;

    do {
        switch (objects) {
            case 1:		Point		break;
            case 2:		Vector		break;
            case 3:		Line		break;
            case 4:		Segment		break;
            case 5:		Triangle	break;
			case 6:		Clear		break;
            case 0:		Exit		break;
			default:	Error		break;
        }
    } while (running);

    return 0;
}
