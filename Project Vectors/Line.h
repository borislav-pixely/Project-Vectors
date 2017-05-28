#ifndef LINE_H
#define LINE_H

#include "Vector.h"
#include "Element.h"
#include "String.h"
#include <iostream>

class Line : public Vector {
    
public:
    Line(const Point& = Point(), const Vector& = Vector());
	Line(const Point&, const Point&);
	Line(const Line&);
    
    Vector direction() const;
    Vector normal_vector() const;
    double angle_between(const Line&) const;
    
    bool operator + (const Point&) const;
    bool operator || (const Line&) const;
    bool operator == (const Line&) const;
    bool operator && (const Line&) const;
    bool operator != (const Line&) const;
    bool operator |  (const Line&) const;
    
    std::ostream& extractor(std::ostream&) const;
    std::istream& inserter(std::istream&);
    
private:
	String name;
    Vector vector;
    Point point;
    
};

std::ostream& operator << (std::ostream&, const Line&);
std::istream& operator >> (std::istream&, Line&);

#endif /* LINE_H */
