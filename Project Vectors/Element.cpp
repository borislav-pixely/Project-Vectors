#include "Element.h"

std::ostream& Element::extractor(std::ostream& out) const {
	return out;
}

std::istream& Element::inserter(std::istream& in) {
	return in;
}
