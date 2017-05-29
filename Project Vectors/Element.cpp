#include "Element.h"

std::ostream& Element::inserter(std::ostream& out) const {
	return out;
}

std::istream& Element::extractor(std::istream& in) {
	return in;
}
