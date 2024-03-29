#include "VectorLengthException.h"
#include "SafeInput.h"
#include "String.h"
#include "Vector.h"
#include "Point.h"
#include <iostream>
#include <iomanip>
#include <cmath>

Vector::Vector(String name, double x, double y, double z) : 
						    name(name), x(x), y(y), z(z) {}

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
    return Vector("- ������", x / length, y / length, z / length);
}

Vector Vector::projection(const Vector& proj) const {
	if (proj.length() == 0)
		throw VectorLengthException();
	return (proj * ((*this * proj) / (proj.length() * proj.length())));
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
    return (x == 0) && (y == 0) && (z == 0);
}

Vector Vector::operator + (const Vector& right) const {
    return Vector("- ����", x + right.x, y + right.y, z + right.z);
}

Vector Vector::operator - (const Vector& right) const {
    return Vector("- �������", x - right.x, y - right.y, z - right.z);
}

Vector Vector::operator * (const double r) const {
    return Vector("- ������������ � �����", x * r, y * r, z * r);
}

double Vector::operator * (const Vector& right) const {
    return x * right.x + y * right.y + z * right.z;
}

Vector Vector::operator ^ (const Vector& right) const {
	return Vector("- �������� ������������", 
				  y * right.x - z * right.y,
				  -x * right.z + z * right.x,
				  x * right.y - y * right.x);
}

double Vector::operator () (const Vector& V, const Vector& W) const {
    return (*this ^ V) * W;
}

double Vector::get_x() const {
	return x;
}

double Vector::get_y() const {
	return y;
}

double Vector::get_z() const {
	return z;
}

String Vector::get_name() const {
	return name.get_string();
}

Vector& Vector::operator << (double value) {
	if (x == 0.) x = value;
	else if (y == 0.) y = value;
	else if (z == 0.) z = value;
	return *this;
}

std::ostream& Vector::inserter(std::ostream& out) const {
	return out << std::setprecision(4) << std::fixed
			   << "\n ������ " << name.get_string()
			   << "\n ( " << x << " )"
			   << "\n ( " << y << " )"
			   << "\n ( " << z << " )";
}

std::istream& Vector::extractor(std::istream& in) {
	SafeInput<double> sin;
	std::cout << " ����, �������� ��� �� ������� (��������): ";
	in >> name;
    std::cout << " ����, �������� �������� �� x: ";
    sin >> x;
    std::cout << " ����, �������� �������� �� y: ";
    sin >> y;
    std::cout << " ����, �������� �������� �� z: ";
    sin >> z;
    return in;
}

std::ostream& operator << (std::ostream& out, const Vector& vector) {
    return vector.inserter(out);
}

std::istream& operator >> (std::istream& in, Vector& vector) {
    return vector.extractor(in);
}
