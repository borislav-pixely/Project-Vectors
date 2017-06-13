#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(String name, const Point& A, const Point& B, 
						 const Point& C, const Point& D) :
						 name(name), A(A), B(B), C(C), D(D) {}

String Tetrahedron::get_name() const {
	return name.get_string();
}

std::ostream& Tetrahedron::inserter(std::ostream& out) const {
	return out << get_name();
}

std::istream& Tetrahedron::extractor(std::istream& in) {
	return in >> name;
}

std::ostream& operator << (std::ostream& out, const Tetrahedron& tetrahedron) {
	return tetrahedron.inserter(out);
}

std::istream& operator >> (std::istream& in, Tetrahedron& tetrahedron) {
	return tetrahedron.extractor(in);
}
