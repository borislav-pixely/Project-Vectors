#include "Segment.h"

Segment::Segment(const Line& line) : line(line) {}

double Segment::length() const {
    return 0.00;
}

Point Segment::center() const {
	return *new Point();
}

bool Segment::operator == (const Point& point) const {
    return true;
}

std::ostream& Segment::extractor(std::ostream& out) const {
    return out << line;
}

std::istream& Segment::inserter(std::istream& in) {
    std::cout << "Моля, въведете стойности за ?: ";
    in >> line;
    return in;
}

std::ostream& operator << (std::ostream& out, const Segment& segment) {
    return segment.extractor(out);
}

std::istream& operator >> (std::istream& in, Segment& segment) {
    return segment.inserter(in);
}
