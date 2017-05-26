#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

class Element {
    
public:
    virtual std::ostream& extractor(std::ostream&) const = 0;
    virtual std::istream& inserter(std::istream&) = 0;
    
};

#endif /* ELEMENT_H */
