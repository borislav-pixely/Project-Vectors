#include "Point.h"
#include "String.h"
#include "SafeInput.h"
#include <iomanip>
#include <iostream>

Point::Point(String name, double x, double y, double z) : 
						   name(name), x(x), y(y), z(z) {}

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

int Point::set_x(double x) {
	this->x = x;
	return 0;
}

int Point::set_y(double y) {
	this->y = y;
	return 0;
}

int Point::set_z(double z) {
	this->z = z;
	return 0;
}

Point& Point::operator << (double value) {
	if (x == 0) x = value;
	else if (y == 0) y = value;
	else if (z == 0) z = value;
	return *this;
}

String Point::get_name() const {
	return name.get_string();
}

std::ostream& Point::inserter(std::ostream& out) const {
    return out <<  std::setprecision(4) << std::fixed 
			   << "(" << x << ", "<< y << ", " << z << ")";
}

std::istream& Point::extractor(std::istream& in) {
	SafeInput<double> sin;
	std::cout << " Моля, въведете име на точката (латиница): ";
	in >> name;
    std::cout << " Моля, въведете стойност за x: ";
    sin >> x;
    std::cout << " Моля, въведете стойност за y: ";
    sin >> y;
    std::cout << " Моля, въведете стойност за z: ";
    sin >> z;
    return in;
}

std::ostream& operator << (std::ostream& out, const Point& point) {
    return point.inserter(out);
}

std::istream& operator >> (std::istream& in, Point& point) {
    return point.extractor(in);
}
