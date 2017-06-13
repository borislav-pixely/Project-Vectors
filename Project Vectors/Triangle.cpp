#include "Triangle.h"
#include "EqualPointException.h"
#include <cmath>

Triangle::Triangle(String name, const Point& A, const Point& B, const Point& C) :
                                                  name(name), A(A), B(B), C(C) {
	//if (A == B || B == C || A == C)
		//throw EqualPointException(A, B, C);
}

double Triangle::area() const {
	return sqrt(pow(A.get_y() * B.get_z() - A.get_z() * B.get_y(), 2) +
				pow(A.get_z() * B.get_x() - A.get_x() * B.get_z(), 2) +
				pow(A.get_x() * B.get_y() - A.get_y() * B.get_x(), 2)) / 2 / 10;
}

double Triangle::perimiter() const {
	return sqrt(pow(A.get_x() - B.get_x(), 2) +
				pow(A.get_y() - B.get_y(), 2) +
				pow(A.get_z() - B.get_z(), 2))  +
		   sqrt(pow(B.get_x() - C.get_x(), 2) +
				pow(B.get_y() - C.get_y(), 2) +
				pow(B.get_z() - C.get_z(), 2))  +
		   sqrt(pow(A.get_x() - C.get_x(), 2) +
				pow(A.get_y() - C.get_y(), 2) +
				pow(A.get_z() - C.get_z(), 2));
}

const char* Triangle::type() const {
	return "Alfa romeo";
}

String Triangle::get_name() const {
	return name.get_string();
}

Triangle& Triangle::operator << (double value) {
	A << value;
	B << value;
	C << value;
	return *this;
}

Point Triangle::medicenter() const {
	return Point();
}

std::ostream& Triangle::inserter(std::ostream& out) const {
    return out << A << B << C;
}

std::istream& Triangle::extractor(std::istream& in) {
	std::cout << " Моля, въведете име на триъгълника (латиница): ";
	in >> name;
	in >> A;
	in >> B;
	in >> C;
    return in;
}

std::ostream& operator << (std::ostream& out, const Triangle& triangle) {
    return triangle.inserter(out);
}

std::istream& operator >> (std::istream& in, Triangle& triangle) {
    return triangle.extractor(in);
}