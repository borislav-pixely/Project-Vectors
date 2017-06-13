#include <clocale>
#include <iostream>
#include <fstream>
#include <string>
#define objects menu("main")
#define Clear clear_console();
#define Error error("Невалиден избор");
#define Automatic automatic = true; running = false;
#define Line while (line_(menu("line")) == 'y') {}
#define Point while (point_(menu("point")) == 'y') {}
#define Vector while (vector_(menu("vector")) == 'y') {}
#define Segment while (segment_(menu("segment")) == 'y') {}
#define Triangle while (triangle_(menu("triangle")) == 'y') {}
#define Tetrahedron while(tetrahedron_(menu("tetra")) == 'y') {}
#define Exit std::cout << " Хубав ден!" << std::endl; running = false;

char line_(unsigned short, std::string = "Empty", bool automatic = false);
char point_(unsigned short, std::string = "Empty", bool automatic = false);
char vector_(unsigned short, std::string = "Empty", bool automatic = false);
char segment_(unsigned short, std::string = "Empty", bool automatic = false);
char triangle_(unsigned short, std::string = "Empty", bool automatic = false);
char tetrahedron_(unsigned short, std::string = "Empty", bool automatic = false);
void error(char*, char* = "");
void garbage_collector();
void clear_console();
int menu(char*);

bool running = true;
bool tetrahedron = false;
bool automatic = false;
bool triangle = false;
bool segment = false;
bool vector = false;
bool point = false;
bool line = false;

int main(int argc, const char* argv[]) {

	std::setlocale(LC_ALL, "bulgarian");

	/* -------------- Menu -------------- */
	do {
		switch (objects) {
			case 1:		Point		break;
			case 2:		Vector		break;
			case 3:		Line		break;
			case 4:		Segment		break;
			case 5:		Triangle	break;
			case 6:		Tetrahedron break;
			case 7:		Clear		break;
			case 8:		Automatic	break;
			case 0:		Exit		break;
			default:	Error		break;
		}
	} while (running);
	/* -------------- Menu -------------- */

	if (automatic) {
		std::string str;
		int iteration = 0;
		int operation = 0;
		std::ifstream file("input.txt");
		while (std::getline(file, str)) {
			switch (iteration) {
				case 0:
					if (str == "Tetrahedron") tetrahedron = true;
					else if (str == "Triangle") triangle = true;
					else if (str == "Segment") segment = true;
					else if (str == "Vector") vector = true;
					else if (str == "Point") point = true;
					else if (str == "Line") line = true;
					break;
				case 1:
					operation = std::stoi(str);
					break;
				default:
					if (tetrahedron) while (tetrahedron_(operation, str, true));
					else if (triangle) while (triangle_(operation, str, true));
					else if (segment) while (segment_(operation, str, true));
					else if (vector) while (vector_(operation, str, true));
					else if (point) while (point_(operation, str, true));
					else if (line) while (line_(operation, str, true));
			}
			iteration++;
		}
		garbage_collector();
	}

    return 0;
}
