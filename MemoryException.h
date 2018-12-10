//
// Created by illya on 11/28/2018.
//

#ifndef OOP_LAB_6_MEMORYEXCEPTION_H
#define OOP_LAB_6_MEMORYEXCEPTION_H

#include "Exception.h"

class MemoryException: public Exception {
private:
    int position;
public:
    explicit MemoryException(const char* error, int culprit): position(culprit), Exception(error) {};

};


#endif //OOP_LAB_6_MEMORYEXCEPTION_H
