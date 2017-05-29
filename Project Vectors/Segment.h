#ifndef SEGMENT_H
#define SEGMENT_H

#include "Line.h"
#include "Element.h"
#include <iostream>

class Segment : public Line {
    
public:
    Segment(const Line&);
    
    double length() const;
    Point center() const;
    
    bool operator == (const Point&) const;
    
    std::ostream& inserter(std::ostream&) const;
    std::istream& extractor(std::istream&);
    
private:
    Line line;
    double t[2];
    
};

std::ostream& operator << (std::ostream&, const Segment&);
std::istream& operator >> (std::istream&, Segment&);

#endif /* SEGMENT_H */
