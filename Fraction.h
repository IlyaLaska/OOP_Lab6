//
// Created by illya on 10/17/2018.
//

#ifndef OOP_LAB_6_FRACTION_H
#define OOP_LAB_6_FRACTION_H

#include <vector>
#include "Bignum.h"

class Fraction {
private:
    Bignum numerator;
    Bignum denominator;
    bool isPositive;
public:
    const Bignum &getNumerator() const;
    const Bignum &getDenominator() const;
    Bignum euclideanAlgorithm (Bignum a, Bignum b);
    bool getIsPositive() const;

    void setIsPositive(bool isPositive);

    Fraction();
    Fraction(Bignum num, Bignum denom);
    Fraction operator-();
    Fraction& operator++();
    const Fraction operator++(int);
    Fraction& operator--();
    const Fraction operator--(int);
    bool operator==(const Fraction &frac) const;
    bool operator!=(const Fraction &frac) const;
//    bool operator>(const Fraction &frac);
//    bool operator<(Fraction &frac);
//    bool operator>=(Fraction &frac);
//    bool operator<=(Fraction &frac);
    explicit operator bool() const;
    Fraction operator+(Fraction &frac);
    Fraction operator-(Fraction &frac);
    Fraction operator*(const Fraction &frac);
    Fraction operator/(Fraction &frac);
//    Fraction operator%(Fraction &frac);
    friend std::ostream& operator<<(std::ostream& output, const Fraction &frac);
};


#endif //OOP_LAB_6_FRACTION_H
