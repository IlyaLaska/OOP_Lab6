//
// Created by illya on 11/21/2018.
//

#ifndef OOP_LAB_6_INPUTEXCEPTION_H
#define OOP_LAB_6_INPUTEXCEPTION_H

#include "Exception.h"
#include <string>
#include <iostream>

template <typename T>
class InputException: public Exception {
private:
//    char inputChar;
    T input;
//    std::string inputStr;
public:
    explicit InputException(const char* error, T culprit): input(culprit), Exception(error) {};
//    explicit InputException(const char* error, const char* culprit): input(culprit), Exception(error) {};
//    explicit InputException(std::string error, const char* culprit): input(culprit), Exception(error) {};
    T getInput() const {return input;}
};


#endif //OOP_LAB_6_INPUTEXCEPTION_H
