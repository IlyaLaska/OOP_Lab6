//
// Created by illya on 11/28/2018.
//

#ifndef OOP_LAB_6_DIVIDEBYZEROEXCEPTION_H
#define OOP_LAB_6_DIVIDEBYZEROEXCEPTION_H

#include "MathException.h"

template <typename T>
class DivideByZeroException: public MathException<T> {
private:
    T firstOperand;
public:
    explicit DivideByZeroException(const char* error, int first, T culprit): firstOperand(first), MathException<T>(error, culprit) {};
    T showFirstOperand() { return firstOperand;};

};


#endif //OOP_LAB_6_DIVIDEBYZEROEXCEPTION_H
