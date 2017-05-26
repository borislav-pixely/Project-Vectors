#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"
#include "Element.h"
#include <iostream>

class Vector : public Element {
    
public:
    Vector(double x = 0., double y = 0., double z = 0.);
    Vector(const Point& A, const Point& B);
    Vector& operator = (const Vector&);
    Vector(const Vector&);
    
    double length() const;
    Vector direction() const;
    
	bool is_a_zero_vector() const;
	bool parallel_to(const Vector&) const;
    bool perpendicular_to(const Vector&) const;
	double projection(const Vector&) const;
    
    Vector operator + (const Vector&) const;
    Vector operator - (const Vector&) const;
    Vector operator * (const double)  const;
    double operator * (const Vector&) const;
    Vector operator ^ (const Vector&) const;
    double operator () (const Vector&, const Vector&) const;
    
    std::ostream& extractor(std::ostream&) const;
    std::istream& inserter(std::istream&);
    
public:
    double x, y, z;
    
};

std::ostream& operator << (std::ostream&, const Vector&);
std::istream& operator >> (std::istream&, Vector&);

#endif /* VECTOR_H */