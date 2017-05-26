#include "Line.h"

Line::Line(const Point& point, const Vector& vector) :
                        point(point), vector(vector) {}

Line::Line(const Point& A, const Point& B) : point(A) {
    vector = *new Vector(A, B);
}

Vector Line::direction() const {
	return *new Vector();
}

Vector Line::normal_vector() const {
	return *new Vector();
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

std::ostream& Line::extractor(std::ostream& out) const {
    return out << vector << point;
}

std::istream& Line::inserter(std::istream& in) {
    std::cout << "Моля, въведете стойности за ?: ";
    in >> vector;
    std::cout << "Моля, въведете стойности за ?: ";
    in >> point;
    return in;
}

std::ostream& operator << (std::ostream& out, const Line& line) {
    return line.extractor(out);
}

std::istream& operator >> (std::istream& in, Line& line) {
    return line.inserter(in);
}
