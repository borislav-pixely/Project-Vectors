#include <clocale>

bool running = true;

int mainMenu();
int lineMenu();
int pointMenu();
int vectorMenu();
int segmentMenu();
int triangleMenu();
char runLineProgram(int);
char runPointProgram(int);
char runVectorProgram(int);
char runSegmentProgram(int);
char runTriangleProgram(int);
void clearConsole();
void resumption();
void error(char*);


int main(int argc, const char* argv[]) {

    std::setlocale(LC_ALL, "bulgarian");

    do {
        switch (mainMenu()) {
            case 1:
                while(runPointProgram(pointMenu()) == 'y') {}
                break;
            case 2:
                while(runVectorProgram(vectorMenu()) == 'y') {}
                break;
            case 3:
                while(runLineProgram(lineMenu()) == 'y') {}
                break;
            case 4:
                while(runSegmentProgram(segmentMenu()) == 'y') {}
                break;
            case 5:
                while(runTriangleProgram(triangleMenu()) == 'y') {}
                break;
			case 6:
				clearConsole();
				break;
            case 0:
				running = false;
                break;
            default:
				error("Невалиден избор");
        }
    } while (running);

    return 0;
}
