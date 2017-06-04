#include "VectorLengthException.h"
#include <exception>
#include <iostream>

VectorLengthException::VectorLengthException() {
    std::cerr << std::endl << " Vector Length Exception" << std::endl;
}
