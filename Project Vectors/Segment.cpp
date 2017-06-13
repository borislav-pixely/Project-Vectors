#include "Segment.h"

Segment::Segment(String name, Line line, double t) : 
				 name(name), line(line), t(t) {}

double Segment::length() const {
    return 0.00;
}

Point Segment::center() const {
	return *new Point();
}

bool Segment::operator == (const Point& C) const {
	return false;
}

Segment& Segment::operator << (double value) {
	line << value;
	return *this;
}

std::ostream& Segment::inserter(std::ostream& out) const {
	return out << line;
}

std::istream& Segment::extractor(std::istream& in) {
    std::cout << "Моля, въведете стойности за отсечката (латиница): ";
	in >> line;
    return in;
}

std::ostream& operator << (std::ostream& out, const Segment& segment) {
    return segment.inserter(out);
}

std::istream& operator >> (std::istream& in, Segment& segment) {
    return segment.extractor(in);
}
