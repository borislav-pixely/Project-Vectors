#include "Line.h"

Line::Line(const Point& point, const Vector& vector) :
           point(point), vector(vector) {}

Line::Line(const Line &line) {
	vector = line.vector;
	point = line.point;
}

Line::Line(const Point& A, const Point& B) : 
	       point(A), vector(*new Vector(A, B)) {}

Vector Line::direction() const {
	return Vector();
}

Vector Line::normal_vector() const {
	return Vector();
}

double Line::angle_between(const Line& right) const {
    return 0.00;
}

bool Line::operator + (const Point& point) const {
    return true;
}

bool Line::operator || (const Line& right) const {
    return true;
}

bool Line::operator == (const Line& right) const {
    return true;
}

bool Line::operator && (const Line& right) const {
    return true;
}

bool Line::operator != (const Line& right) const {
    return true;
}

bool Line::operator | (const Line& right) const {
    return true;
}

std::ostream& Line::inserter(std::ostream& out) const {
    return out << vector << point;
}

std::istream& Line::extractor(std::istream& in) {
	std::cout << "Моля, въведете име за правата (латиница): ";
	in >> name;
    std::cout << "Моля, въведете стойности за вектора на правата: ";
    in >> vector;
    std::cout << "Моля, въведете стойности за точката на правата: ";
	in >> point;
    return in;
}

std::ostream& operator << (std::ostream& out, const Line& line) {
    return line.inserter(out);
}

std::istream& operator >> (std::istream& in, Line& line) {
    return line.extractor(in);
}
