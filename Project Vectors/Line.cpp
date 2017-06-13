#include "Line.h"

Line::Line(String name, const Point& point, const Vector& vector) :
           name(name), point(point), vector(vector) {}

Line::Line(const Line &line) {
	vector = line.vector;
	point = line.point;
}

Line::Line(const Point& A, const Point& B, String name) :
	       name(name), point(A), vector(Vector(A, B)) {}

String Line::get_name() const {
	return name.get_string();
}

Vector Line::direction() const {
	return vector;
}

Vector Line::normal_vector() const {
	return Vector("", -vector.get_x(), vector.get_y(), vector.get_z());
}

double Line::angle_between(const Line& right) const {
    return acos(abs(vector*right.vector) / vector.length() * right.vector.length());
}

bool Line::operator + (const Point& right) const {
	return (point.get_x() == right.get_x() * vector.get_x()
			&& point.get_y() == right.get_y() * vector.get_y()
			&& point.get_z() == right.get_z() * vector.get_z());
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

Line& Line::operator << (double value) {
	point << value;
	vector << value;
	return *this;
}

std::ostream& Line::inserter(std::ostream& out) const {
	return out << vector << point;
}

std::istream& Line::extractor(std::istream& in) {
	std::cout << " Моля, въведете име за правата (латиница): ";
	in >> name;
	std::cout << " Моля, въведете стойности за вектора на правата: " << std::endl;
    in >> vector;
	std::cout << " Моля, въведете стойности за точката на правата: " << std::endl;
	in >> point;
    return in;
}

std::ostream& operator << (std::ostream& out, const Line& line) {
    return line.inserter(out);
}

std::istream& operator >> (std::istream& in, Line& line) {
    return line.extractor(in);
}
