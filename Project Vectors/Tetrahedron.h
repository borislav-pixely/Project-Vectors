#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Point.h"
#include "Element.h"
#include <iostream>

class Tetrahedron : public Point {

public:
	Tetrahedron(const Point& = Point(), const Point& = Point(), 
				const Point& = Point(), const Point& = Point());

	String get_name() const;

	std::ostream& inserter(std::ostream&) const;
	std::istream& extractor(std::istream&);

private:
	Point A, B, C, D;
	String name;

};

std::ostream& operator << (std::ostream&, const Tetrahedron&);
std::istream& operator >> (std::istream&, Tetrahedron&);

#endif /* TETRAHEDRON_H */
