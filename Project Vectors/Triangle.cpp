#include "Triangle.h"
#include "EqualPointException.h"

Triangle::Triangle(const Point& A, const Point& B, const Point& C) :
                                                  A(A), B(B), C(C) {
    if (A == 0 || B == 0 || C == 0)
        throw EqualPointException(A, B, C);
}

double Triangle::area() const {
    return 0.00;
}

double Triangle::perimiter() const {
    return 0.00;
}

const char* Triangle::type() const {
    const char* abc = "abc";
    return abc;
}

Point Triangle::medicenter() const {
	return *new Point();
}

std::ostream& Triangle::inserter(std::ostream& out) const {
    return out << A << B << C;
}

std::istream& Triangle::extractor(std::istream& in) {
    std::cout << "Моля, въведете стойности за точка А: ";
    in >> A;
    std::cout << "Моля, въведете стойности за точка B: ";
    in >> B;
    std::cout << "Моля, въведете стойности за точка C: ";
    in >> C;
    return in;
}

std::ostream& operator << (std::ostream& out, const Triangle& triangle) {
    return triangle.inserter(out);
}

std::istream& operator >> (std::istream& in, Triangle& triangle) {
    return triangle.extractor(in);
}
