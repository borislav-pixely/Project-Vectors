#include "VectorLengthException.h"
#include <exception>
#include <iostream>

VectorLengthException::VectorLengthException() {
    std::cerr << "VECTOR LENGTH EXCEPTION" << std::endl << std::endl;
}
