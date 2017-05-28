#ifndef EQUAL_POINT_EXCEPTION_H
#define EQUAL_POINT_EXCEPTION_H

#include <exception>
#include "Point.h"

class EqualPointException : public std::exception {
    
public:
    EqualPointException(const Point& = Point(),
                        const Point& = Point(),
                        const Point& = Point());
    
};

#endif /* EQUAL_POINT_EXCEPTION_H */
