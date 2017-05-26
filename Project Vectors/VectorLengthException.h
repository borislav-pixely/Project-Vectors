#ifndef VECTOR_LENGTH_EXCEPTION_H
#define VECTOR_LENGTH_EXCEPTION_H

#include <exception>

class VectorLengthException : public std::exception {
    
public:
    VectorLengthException();
    
};

#endif /* VECTOR_LENGTH_EXCEPTION_H */
