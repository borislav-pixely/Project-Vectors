#ifndef LINE_H
#define LINE_H

#include "Vector.h"
#include "Element.h"
#include "String.h"
#include <iostream>

class Line : public Vector {
    
public:
    Line(String name = "L", const Point& = Point(), const Vector& = Vector());
	Line(const Point&, const Point&, String name = "L");
	Line(const Line&);
    
	String get_name() const;
	Vector direction() const;
    Vector normal_vector() const;
    double angle_between(const Line&) const;
    
    bool operator + (const Point&) const;
    bool operator || (const Line&) const;
    bool operator == (const Line&) const;
    bool operator && (const Line&) const;
    bool operator != (const Line&) const;
    bool operator |  (const Line&) const;

	Line& operator << (double);
    
    std::ostream& inserter(std::ostream&) const;
    std::istream& extractor(std::istream&);
    
private:
	String name;
    Vector vector;
    Point point;
    
};

std::ostream& operator << (std::ostream&, const Line&);
std::istream& operator >> (std::istream&, Line&);

#endif /* LINE_H */
