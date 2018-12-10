//
// Created by illya on 11/21/2018.
//

#ifndef OOP_LAB_6_MATHEXCEPTION_H
#define OOP_LAB_6_MATHEXCEPTION_H

#include "Exception.h"
template <typename T>
class MathException: public Exception {
private:
    T error;
public:
    explicit MathException(const char* error, T culprit): error(culprit), Exception(error) {};
    T getError() const {return error;}

};


#endif //OOP_LAB_6_MATHEXCEPTION_H
