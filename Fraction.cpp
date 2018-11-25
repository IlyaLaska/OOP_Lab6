//
// Created by illya on 10/17/2018.
//

#include "Fraction.h"
#include "MathException.h"

Fraction::Fraction() {
//    numerator = Bignum();
//    denominator = Bignum();
}

Fraction::Fraction(Bignum num, Bignum denom) {
    if(denom == Bignum("0")) throw MathException("Tried dividing by zero", denom.number[0]);
    Bignum GCD = euclideanAlgorithm(num, denom);
    Bignum absGCD =  GCD;
    absGCD.isPositive = true;
//    std::cout << "NUM:::  " << num << std::endl;
//    std::cout << "DENOM:::  " << denom << std::endl;
//    std::cout << "gcd::  " << GCD << std::endl;
    if(absGCD > Bignum("1")) {
        num = num / GCD;
        denom = denom / GCD;
    }
//    std::cout << "result" << num << "  " << denominator << std::endl;
    numerator = num;
    denominator = denom;
    if(numerator.isPositive != denominator.isPositive) isPositive = false;
    else isPositive = true;
//    std::cout << "result" << numerator << "  " << denominator << std::endl;
}

Fraction Fraction::operator-() {
    isPositive = !isPositive;
    return *this;
}

Bignum Fraction::euclideanAlgorithm (Bignum a, Bignum b) {
    Bignum c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

std::ostream& operator<<(std::ostream& output, const Fraction &frac) {
//    output << "The fraction is: ";
    if(!frac.isPositive) output << "- ";
    for (long long int i = frac.numerator.number.size()-1; i >= 0; --i) {
        output << frac.numerator.number[i];
    }
    output << "/";
    for (long long int i = frac.denominator.number.size()-1; i >= 0; --i) {
        output << frac.denominator.number[i];
    }
    return output;
}

Fraction &Fraction::operator++() {
    if (isPositive) ++numerator;
    else --numerator;
    return *this;
}
const Fraction Fraction::operator++(int) {
    Fraction copy(*this);
    ++copy;
    return copy;
}

Fraction &Fraction::operator--() {
    if(isPositive) --numerator;
    else ++numerator;
    return *this;
}

const Fraction Fraction::operator--(int) {
    Fraction copy(*this);
    --copy;
    return copy;
}

bool Fraction::operator==(const Fraction &frac) const {
    if(numerator == frac.numerator && denominator == frac.denominator && isPositive == frac.isPositive) return true;
    return false;
}

bool Fraction::operator!=(const Fraction &frac) const {
    return !(*this == frac);
}

Fraction::operator bool() const {
    if(numerator != Bignum("0") && denominator != Bignum("0")) return true;
    return false;
}

Fraction Fraction::operator+(Fraction &frac) {
    if(this->numerator == Bignum("0")) return Fraction(frac.numerator, frac.denominator);
    if(frac.numerator == Bignum("0")) return (*this);
    Bignum thisNum;
    Bignum thisDenom;
    Bignum fracNum;
    if(denominator != frac.denominator) {
        thisNum = this->numerator * frac.denominator;
        thisDenom = this->denominator * frac.denominator;
        fracNum = frac.numerator * this->denominator;
//        frac.denominator = frac.denominator * this->denominator;
    } else {
        thisNum = this->numerator;
        thisDenom = this->denominator;
        fracNum = frac.numerator;
    }
    Bignum numer;
    numer = thisNum+fracNum;
    if(!numer.isPositive && !this->isPositive) numer.isPositive = !numer.isPositive;
    return Fraction(numer, thisDenom);
}

Fraction Fraction::operator-(Fraction &frac) {
    Bignum thisNum;
    Bignum thisDenom;
    Bignum fracNum;
    if(denominator != frac.denominator) {
        thisNum = this->numerator * frac.denominator;
        thisDenom = this->denominator * frac.denominator;
        fracNum = frac.numerator * this->denominator;
//        frac.denominator = frac.denominator * this->denominator;
    } else {
        thisNum = this->numerator;
        thisDenom = this->denominator;
        fracNum = frac.numerator;
    }
    Bignum numer;
    numer = thisNum-fracNum;
    if(!numer.isPositive && !this->isPositive) numer.isPositive = !numer.isPositive;
    return Fraction(numer, thisDenom);
}

Fraction Fraction::operator*(const Fraction &frac) {
    Bignum numerator = this->numerator*frac.numerator;
    Bignum denominator = this->denominator*frac.denominator;
    Fraction result(numerator, denominator);
    if(isPositive != frac.isPositive) result.isPositive = false;
    else result.isPositive = true;
    return result;
}

Fraction Fraction::operator/(Fraction &frac) {
    Bignum numerator = this->numerator*frac.denominator;
    Bignum denominator = this->denominator*frac.numerator;
    Fraction result(numerator, denominator);
    if(isPositive != frac.isPositive) result.isPositive = false;
    else result.isPositive = true;
    return result;
}

bool Fraction::getIsPositive() const {
    return isPositive;
}

void Fraction::setIsPositive(bool isPositive) {
    Fraction::isPositive = isPositive;
}

const Bignum &Fraction::getNumerator() const {
    return numerator;
}

const Bignum &Fraction::getDenominator() const {
    return denominator;
}

//Fraction Fraction::operator%(Fraction &frac) {
//    return Fraction(Bignum(), Bignum());
//}

