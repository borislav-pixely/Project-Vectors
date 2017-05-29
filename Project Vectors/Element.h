#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include "String.h"

class Element {
    
public:
	virtual std::ostream& inserter(std::ostream&) const;
	virtual std::istream& extractor(std::istream&);
    
};


#endif /* ELEMENT_H */
