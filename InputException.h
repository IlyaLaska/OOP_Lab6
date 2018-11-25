//
// Created by illya on 11/21/2018.
//

#ifndef OOP_LAB_6_INPUTEXCEPTION_H
#define OOP_LAB_6_INPUTEXCEPTION_H

#include "Exception.h"
#include <iostream>

class InputException: public Exception {
private:
    char input;
public:
    explicit InputException(const char* error, char culprit): input(culprit), Exception(error) {
//        std::cout << "E"
    };
    char getInput() const {return input;}
};


#endif //OOP_LAB_6_INPUTEXCEPTION_H
