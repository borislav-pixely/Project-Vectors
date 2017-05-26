#ifndef EQUAL_POINT_EXCEPTION_H
#define EQUAL_POINT_EXCEPTION_H

#include <exception>
#include "Point.h"

class EqualPointException : public std::exception {
    
public:
    EqualPointException(const Point& = 0,
                        const Point& = 0,
                        const Point& = 0);
    
};

#endif /* EQUAL_POINT_EXCEPTION_H */
