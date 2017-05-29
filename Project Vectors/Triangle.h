#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Element.h"
#include <iostream>

class Triangle : public Point {
    
public:
    Triangle(const Point&, const Point&, const Point&);
    
    double area() const;
    double perimiter() const;
    const char* type() const;
    Point medicenter() const;
    
    std::ostream& inserter(std::ostream&) const;
    std::istream& extractor(std::istream&);
    
private:
    Point A, B, C;
    
};

std::ostream& operator << (std::ostream&, const Triangle&);
std::istream& operator >> (std::istream&, Triangle&);

#endif /* TRIANGLE_H */
