//
// Created by illya on 10/18/2018.
//

#ifndef OOP_LAB_6_MATRIX_H
#define OOP_LAB_6_MATRIX_H

#include <vector>
#include "Fraction.h"


class Matrix {
private:
    int length = 1;//X
    int height = 1;//Y
    std::vector<Fraction> matrix;
    void fillMatrix();
    Matrix findMinorMat();
    Matrix transposeMat();
    Fraction findDet();
    Fraction findDet(Fraction a, Fraction b, Fraction c, Fraction d);
public:
    Matrix(int Y, int X);
    Matrix() = default;
    Matrix operator-();
    Matrix operator!();
    Matrix operator+(int second);
    Matrix operator-(int second);
    Matrix operator*(int second);
    Matrix operator/(int second);
    Matrix operator+(Bignum second);
    Matrix operator-(Bignum second);
    Matrix operator*(Bignum second);
    Matrix operator/(Bignum second);
    Matrix operator+(Fraction &second);
    Matrix operator-(Fraction &second);
    Matrix operator*(const Fraction &second);
    Matrix operator/(Fraction &second);
    Matrix operator+(Matrix &second);
    Matrix operator-(Matrix &second);
    Matrix operator*(const Matrix &second);
    Matrix operator/(Matrix &second);
    Matrix operator+=(int second);
    Matrix operator-=(int second);
    Matrix operator*=(int second);
    Matrix operator/=(int second);
    Matrix operator+=(Bignum second);
    Matrix operator-=(Bignum second);
    Matrix operator*=(Bignum second);
    Matrix operator/=(Bignum second);
    Matrix operator+=(Fraction &second);
    Matrix operator-=(Fraction &second);
    Matrix operator*=(const Fraction &second);
    Matrix operator/=(Fraction &second);
    Matrix operator+=(Matrix &second);
    Matrix operator-=(Matrix &second);
    Matrix operator*=(const Matrix &second);
    Matrix operator/=(Matrix &second);
    friend std::ostream& operator<<(std::ostream& output, const Matrix &matrix);
    friend void fillMatrix(Matrix &mat);
};


#endif //OOP_LAB_6_MATRIX_H
