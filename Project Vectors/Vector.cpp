#include "VectorLengthException.h"
#include "Vector.h"
#include "Point.h"
#include <iostream>
#include <iomanip>
#include <cmath>

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

Vector::Vector(const Point& A, const Point& B) {
    x = B.get_x() - A.get_x();
    y = B.get_y() - A.get_y();
    z = B.get_z() - A.get_z();
}

Vector& Vector::operator = (const Vector& right) {
    if (this != &right) {
        x = right.x;
        y = right.y;
        z = right.z;
    }
    return *this;
}

Vector::Vector(const Vector& right) {
    x = right.x;
    y = right.y;
    z = right.z;
}

double Vector::length() const {
    return sqrt(x * x + y * y + z * z);
}

Vector Vector::direction() const {
    double length = this->length();
    if (this->length() == 0)
        throw VectorLengthException();
    return *new Vector(x / length, y / length, z / length);
}

double Vector::projection(const Vector& proj) const {
    return this->length() * proj.length();
}

bool Vector::perpendicular_to(const Vector& right) const {
    if (this->length() == 0 || right.length() == 0)
        throw VectorLengthException();
    if (*this * right == 0) return true;
    else return false;
}

bool Vector::parallel_to(const Vector& right) const {
    if (this->length() == 0 || right.length() == 0)
        throw VectorLengthException();
    return this->x / right.x == this->y / right.y == this->z / right.z;
}

bool Vector::is_a_zero_vector() const {
    return x == y == z == 0;
}

Vector Vector::operator + (const Vector& right) const {
    return *new Vector(x + right.x, y + right.y, z + right.z);
}

Vector Vector::operator - (const Vector& right) const {
    return *new Vector(x - right.x, y - right.y, z - right.z);
}

Vector Vector::operator * (const double r) const {
    return *new Vector(x * r, y * r, z * r);
}

double Vector::operator * (const Vector& right) const {
    return x * right.x + y * right.y + z * right.z;
}

Vector Vector::operator ^ (const Vector& right) const {
	return *new Vector(y * right.x - z * right.y,
					   -x * right.z + z * right.x,
					   x * right.y - y * right.x);
}

double Vector::operator () (const Vector& V, const Vector& W) const {
    return (*this ^ V) * W;
}

std::ostream& Vector::extractor(std::ostream& out) const {
	return out << std::setprecision(4) << std::fixed
			   << "\n Вектор " << name
			   << "\n ( " << x << " )"
			   << "\n ( " << y << " )"
			   << "\n ( " << z << " )";
}

std::istream& Vector::inserter(std::istream& in) {
	std::cout << "Моля, въведете име на вектора (латиница): ";
	in >> name;
    std::cout << "Моля, въведете стойност за x: ";
    in >> x;
    std::cout << "Моля, въведете стойност за y: ";
    in >> y;
    std::cout << "Моля, въведете стойност за z: ";
    in >> z;
    return in;
}

std::ostream& operator << (std::ostream& out, const Vector& vector) {
    return vector.extractor(out);
}

std::istream& operator >> (std::istream& in, Vector& vector) {
    return vector.inserter(in);
}
