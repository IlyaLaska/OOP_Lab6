//
// Created by illya on 11/21/2018.
//

#ifndef OOP_LAB_6_EXCEPTION_H
#define OOP_LAB_6_EXCEPTION_H


class Exception {
private:
    const char* error;
public:
    explicit Exception(const char* err): error(err) {};
    const char* what() { return error;};

};


#endif //OOP_LAB_6_EXCEPTION_H
