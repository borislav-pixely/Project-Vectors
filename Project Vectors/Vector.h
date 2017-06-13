#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"
#include "Element.h"
#include "String.h"
#include <iostream>

class Vector : public Point {
    
public:
    Vector(String name = "V", double x = 0., double y = 0., double z = 0.);
    Vector(const Point& A, const Point& B);
    Vector& operator = (const Vector&);
    Vector(const Vector&);
    
    double length() const;
    Vector direction() const;
	String get_name() const;
    
	bool is_a_zero_vector() const;
	bool parallel_to(const Vector&) const;
    bool perpendicular_to(const Vector&) const;
	Vector projection(const Vector&) const;
    
    Vector operator + (const Vector&) const;
    Vector operator - (const Vector&) const;
    Vector operator * (const double)  const;
    double operator * (const Vector&) const;
    Vector operator ^ (const Vector&) const;
    double operator () (const Vector&, const Vector&) const;

	double get_x() const;
	double get_y() const;
	double get_z() const;

	Vector& operator << (double);
    
    std::ostream& inserter(std::ostream&) const;
    std::istream& extractor(std::istream&);
    
public:
	String name;
    double x, y, z;
    
};

std::ostream& operator << (std::ostream&, const Vector&);
std::istream& operator >> (std::istream&, Vector&);

#endif /* VECTOR_H */
