#ifndef LINE_H
#define LINE_H

#include "Vector.h"
#include "Element.h"
#include <iostream>

class Line : public Element {
    
public:
    Line(const Point& = *new Point, const Point&  = *new Point);
    Line(const Point& = *new Point, const Vector& = *new Vector);
    
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
    Vector vector;
    Point point;
    
};

std::ostream& operator << (std::ostream&, const Line&);
std::istream& operator >> (std::istream&, Line&);

#endif /* LINE_H */