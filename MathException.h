//
// Created by illya on 11/21/2018.
//

#ifndef OOP_LAB_6_MATHEXCEPTION_H
#define OOP_LAB_6_MATHEXCEPTION_H

#include "Exception.h"

class MathException: public Exception {
private:
    int error;
public:
    explicit MathException(const char* error, int culprit): error(culprit), Exception(error) {};
    int getError() const {return error;}

};


#endif //OOP_LAB_6_MATHEXCEPTION_H
