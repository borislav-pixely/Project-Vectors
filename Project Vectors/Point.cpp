#include "Point.h"
#include <iomanip>
#include <iostream>

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

Point& Point::operator = (const Point& right) {
    if (this != &right) {
        x = right.x;
        y = right.y;
        z = right.z;
    }
    return *this;
}

Point::Point(const Point& right) {
    x = right.x;
    y = right.y;
    z = right.z;
}

bool Point::operator == (const Point& right) const {
    return x == right.x && y == right.y && z == right.z;
}

bool Point::operator == (int num) const {
    return x == num && y == num && z == num;
}

double Point::get_x() const {
    return x;
}

double Point::get_y() const {
    return y;
}

double Point::get_z() const {
    return z;
}

std::ostream& Point::extractor(std::ostream& out) const {
    return out <<  std::setprecision(4) << std::fixed 
			   << "(" << x << ", "<< y << ", " << z << ")";
}

std::istream& Point::inserter(std::istream& in) {
	std::cout << " ����, �������� ��� �� ������� (��������): ";
	in >> name;
    std::cout << " ����, �������� �������� �� x: ";
    in >> x;
    std::cout << " ����, �������� �������� �� y: ";
    in >> y;
    std::cout << " ����, �������� �������� �� z: ";
    in >> z;
    return in;
}

std::ostream& operator << (std::ostream& out, const Point& point) {
    return point.extractor(out);
}

std::istream& operator >> (std::istream& in, Point& point) {
    return point.inserter(in);
}
