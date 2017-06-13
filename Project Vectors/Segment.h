#ifndef SEGMENT_H
#define SEGMENT_H

#include "Line.h"
#include "Element.h"
#include <iostream>

class Segment : public Line {
    
public:
    Segment(String = "S", Line = Line(), double = 0);
    
    double length() const;
    Point center() const;
    
    bool operator == (const Point&) const;

	Segment& operator << (double);
    
    std::ostream& inserter(std::ostream&) const;
    std::istream& extractor(std::istream&);
    
private:
	String name;
	Line line;
	double t;
    
};

std::ostream& operator << (std::ostream&, const Segment&);
std::istream& operator >> (std::istream&, Segment&);

#endif /* SEGMENT_H */
