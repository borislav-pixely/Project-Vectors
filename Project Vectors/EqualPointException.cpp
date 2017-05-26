#include "EqualPointException.h"
#include <exception>
#include <iostream>

EqualPointException::EqualPointException(const Point& A,
                                         const Point& B,
                                         const Point& C) {
    std::cerr << "EQUAL POINT EXCEPTION" << std::endl;
    std::cerr << "CULPRITS: ";
    if (A == 0) std::cerr << "POINT A; ";
    if (B == 0) std::cerr << "POINT B; ";
    if (C == 0) std::cerr << "POINT C; ";
    std::cerr << std::endl << std::endl;
}
