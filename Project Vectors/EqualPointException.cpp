#include "EqualPointException.h"
#include <exception>
#include <iostream>

EqualPointException::EqualPointException(const Point& A,
                                         const Point& B,
                                         const Point& C) {
    std::cerr << " Equal Point Exception" << std::endl;
    std::cerr << " Culprits: ";
    if (A == B) std::cerr << "Point A == B; ";
    if (B == C) std::cerr << "Point B == C; ";
    if (C == A) std::cerr << "Point A == C; ";
	std::cerr << std::endl;
}
