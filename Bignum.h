//
// Created by illya on 10/4/2018.
//

#ifndef OOP_LAB_6_BIGNUM_H
#define OOP_LAB_6_BIGNUM_H

#include <vector>
#include <string>
#include <iostream>

class Bignum {
private:
    int getDigit(int digit) const;
    void handlePositiveCarry();
    void handleNegativeCarry();
    void removeLeadingZeroes();
    bool isZero() const;
    Bignum abs(const Bignum &num);
public:
    std::vector<int> number;
    bool isPositive = true;
    Bignum();
    Bignum(std::string number);
    Bignum operator-();
    Bignum& operator++();
    const Bignum operator++(int);
    Bignum& operator--();
    const Bignum operator--(int);
    bool operator==(const Bignum &num) const;
    bool operator!=(const Bignum &num) const;
    bool operator>(const Bignum &num);
    bool operator<(Bignum &num);
    bool operator>=(Bignum &num);
    bool operator<=(Bignum &num);
    explicit operator bool() const;
    Bignum operator+(Bignum &num);
    Bignum operator-(Bignum &num);
    Bignum operator*(const Bignum &num);
    Bignum operator/(Bignum &num);
    Bignum operator%(Bignum &num);
//    Bignum& operator/(int a);
//    Bignum& operator=(std::string input);
    friend std::ostream& operator<<(std::ostream& output, const Bignum& num);
};



#endif //OOP_LAB_6_BIGNUM_H
