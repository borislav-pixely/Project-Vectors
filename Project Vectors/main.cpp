#include <clocale>
#define menu_options menu("main")
#define clear_history clear_console();
#define start_line_program while (line_program(menu("line")) == 'y') {}
#define start_point_program while (point_program(menu("point")) == 'y') {}
#define start_vector_program while (vector_program(menu("vector")) == 'y') {}
#define start_segment_program while (segment_program(menu("segment")) == 'y') {}
#define start_triangle_program while (triangle_program(menu("triangle")) == 'y') {}

int menu(char*);
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
        switch (menu_options) {
            case 1:
				start_point_program
                break;
            case 2:
				start_vector_program
                break;
            case 3:
				start_line_program
                break;
            case 4:
				start_segment_program
                break;
            case 5:
				start_triangle_program
                break;
			case 6:
				clear_history
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
