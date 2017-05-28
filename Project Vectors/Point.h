#ifndef POINT_H
#define POINT_H

#include "Element.h"
#include "String.h"
#include <iostream>

class Point : public Element {
    
public:
    Point(double x = 0., double y = 0., double z = 0.);
    Point& operator = (const Point&);
    Point(const Point&);
    
    bool operator == (const Point&) const;
    bool operator == (int) const;
    
    double get_x() const;
    double get_y() const;
    double get_z() const;
    
    std::ostream& extractor(std::ostream&) const;
    std::istream& inserter(std::istream&);
    
private:
	String name;
    double x, y, z;
    
};

std::ostream& operator << (std::ostream&, const Point&);
std::istream& operator >> (std::istream&, Point&);

#endif /* POINT_H */
