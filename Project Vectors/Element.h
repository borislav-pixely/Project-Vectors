#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include "String.h"

class Element {
    
public:
	virtual std::ostream& extractor(std::ostream&) const;
	virtual std::istream& inserter(std::istream&);
    
};

#endif /* ELEMENT_H */
