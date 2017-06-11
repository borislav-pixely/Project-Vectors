#include <clocale>
#define objects menu("main", input)
#define Clear clear_console();
#define Exit running = false;
#define Error error("Невалиден избор");
#define Line while (line_program(menu("line", input)) == 'y') {}
#define Point while (point_program(menu("point", input)) == 'y') {}
#define Vector while (vector_program(menu("vector", input)) == 'y') {}
#define Segment while (segment_program(menu("segment", input)) == 'y') {}
#define Triangle while (triangle_program(menu("triangle", input)) == 'y') {}
#define File input = "file";
#define Fix input = "cin";
char* input = "cin";

int menu(char*, char*);
char line_program(int);
char point_program(int);
char vector_program(int);
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
			case 7:		File		break;
            case 0:		Exit		break;
			case -1:	Fix 		break;
			default:	Error		break;
        }
    } while (running);

    return 0;
}
