//
// Created by illya on 10/18/2018.
//

#include "Matrix.h"
#include <iostream>
#include <string>

Matrix::Matrix(int Y, int X) : matrix(Y*X, Fraction( Bignum("0"), Bignum("1") ) ), height(Y), length(X) {
    if(Y == 0 || X == 0) {
        std::cout << "Matrix cannot be 0 in size" << std::endl;
        throw;
    }
//    std::cout << "Please enter your matrix elements:" << std::endl;
    fillMatrix();
}

void Matrix::fillMatrix() {
    for (int i = 0; i < length; ++i) {
        matrix[i] = Fraction(Bignum("0"), Bignum("1"));
    }
}

std::ostream &operator<<(std::ostream &output, const Matrix &matrix) {
//    for (int i = 0; i < matrix.height; ++i) {
//        for (int j = i*matrix.length; j < (i+1)*matrix.length; ++j) {
//            output << matrix.matrix[j] << " ";
//        }
//        output << std::endl;
//    }
//    output << std::endl;
    std::cout << "The Matrix is:  " << std::endl;
    for (int k = 0; k < matrix.matrix.size(); ++k) {
        output << matrix.matrix[k] << " ";
        if((k+1)%matrix.length == 0) output << std::endl;
    }
    return output;
}

Matrix Matrix::operator-() {
    for (auto &i : matrix) {
        i.setIsPositive(!i.getIsPositive());
    }
    return *this;
}

Matrix Matrix::operator+(int second) {
    std::string str = std::to_string(second);
    Fraction frac(Bignum(str),Bignum("1"));
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] + frac;
    }
    return copy;
}

Matrix Matrix::operator-(int second) {
    std::string str = std::to_string(second);
    Fraction frac(Bignum(str),Bignum("1"));
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] - frac;
    }
    return copy;
}

Matrix Matrix::operator*(int second) {
    std::string str = std::to_string(second);
    Fraction frac(Bignum(str),Bignum("1"));
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] * frac;
    }
    return copy;
}

Matrix Matrix::operator/(int second) {
    std::string str = std::to_string(second);
    Fraction frac(Bignum(str),Bignum("1"));
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] / frac;
    }
    return copy;
}

Matrix Matrix::operator+(Bignum second) {
    Fraction frac(std::move(second),Bignum("1"));
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] + frac;
    }
    return copy;
}

Matrix Matrix::operator-(Bignum second) {
    Fraction frac(std::move(second),Bignum("1"));
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] - frac;
    }
    return copy;
}

Matrix Matrix::operator*(Bignum second) {
    Fraction frac(std::move(second),Bignum("1"));
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] * frac;
    }
    return copy;
}

Matrix Matrix::operator/(Bignum second) {
    Fraction frac(std::move(second),Bignum("1"));
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] / frac;
    }
    return copy;
}

Matrix Matrix::operator+(Fraction &second) {
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] + second;
    }
    return copy;
}

Matrix Matrix::operator-(Fraction &second) {
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] - second;
    }
    return copy;
}

Matrix Matrix::operator*(const Fraction &second) {
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] * second;
    }
    return copy;}

Matrix Matrix::operator/(Fraction &second) {
    Matrix copy(*this);
    for (int i = 0; i < matrix.size(); ++i) {
        copy.matrix[i] = matrix[i] / second;
    }
    return copy;
}

Matrix Matrix::operator+(Matrix &second) {
    if(this->height != second.height && this->length != second.length) {
        std::cout << "Cannot add matrices with different sizes!" << std::endl;
        return (*this);
    }
    for (int i = 0; i < matrix.size(); ++i) {
        this->matrix[i] = this->matrix[i] + second.matrix[i];
    }
    return (*this);
}

Matrix Matrix::operator-(Matrix &second) {
    if(this->height != second.height && this->length != second.length) {
        std::cout << "Cannot subtract matrices with different sizes!" << std::endl;
        return (*this);
    }
    for (int i = 0; i < matrix.size(); ++i) {
        this->matrix[i] = this->matrix[i] - second.matrix[i];
    }
    return (*this);
}

Matrix Matrix::operator*(const Matrix &second) {
    if(this->length != second.height /*&& this->length != second.*/) {
        std::cout << "Cannot multiply matrices with different sizes!" << std::endl;
        return (*this);
    }
    Matrix copy(this->height, second.length);
    for (int i = 0; i < copy.matrix.size(); ++i) {
        for (int j = 0; j < this->length; ++j) {
            int heightOp = 0;
            for (int k = 0; k < j; ++k) {
                heightOp += second.length;
            }
            Fraction add = this->matrix[j] * second.matrix[heightOp];
//            std::cout << "Old copy:" << std::endl;
//            std::cout << copy.matrix[i] << std::endl;
            copy.matrix[i] = copy.matrix[i] + add;


//            std::cout << "OPERANDS:" << std::endl;
//            std::cout << this->matrix[j] << std::endl;
//            std::cout << second.matrix[heightOp] << std::endl;//still same i i%second.length
//            std::cout << "ADD RESULT:" << std::endl;
//            std::cout << add << std::endl;
//            std::cout << "COPY:" << std::endl;
//            std::cout << copy.matrix[i] << std::endl;
//                std::cout << "j:" << j << std::endl;
        }
//        std::cout << "i:" << i << std::endl;

    }
    return copy;
}

Matrix Matrix::operator/(Matrix &second) {
    return Matrix();
}

Matrix Matrix::operator+=(int second) {
    (*this) = (*this) + second;
    return (*this);
}

Matrix Matrix::operator-=(int second) {
    (*this) = (*this) - second;
    return (*this);
}

Matrix Matrix::operator*=(int second) {
    (*this) = (*this) * second;
    return (*this);
}

Matrix Matrix::operator/=(int second) {
    (*this) = (*this) / second;
    return (*this);
}

Matrix Matrix::operator+=(Bignum second) {
    (*this) = (*this) + std::move(second);
    return (*this);
}

Matrix Matrix::operator-=(Bignum second) {
    (*this) = (*this) - std::move(second);
    return (*this);
}

Matrix Matrix::operator*=(Bignum second) {
    (*this) = (*this) * std::move(second);
    return (*this);
}

Matrix Matrix::operator/=(Bignum second) {
    (*this) = (*this) / std::move(second);
    return (*this);
}

Matrix Matrix::operator+=(Fraction &second) {
    (*this) = (*this) + second;
    return (*this);
}

Matrix Matrix::operator-=(Fraction &second) {
    (*this) = (*this) - second;
    return (*this);
}

Matrix Matrix::operator*=(const Fraction &second) {
    (*this) = (*this) * second;
    return (*this);
}

Matrix Matrix::operator/=(Fraction &second) {
    (*this) = (*this) / second;
    return (*this);
}

Matrix Matrix::operator+=(Matrix &second) {
    (*this) = (*this) + second;
    return (*this);
}

Matrix Matrix::operator-=(Matrix &second) {
    (*this) = (*this) - second;
    return (*this);
}

Matrix Matrix::operator*=(const Matrix &second) {
    (*this) = (*this) * second;
    return (*this);
}

Matrix Matrix::operator/=(Matrix &second) {
    (*this) = (*this) / second;
    return (*this);
}

Matrix Matrix::operator!() {
    if(length != height) {
        std::cout << "cannot invert non-square matrix" << std::endl;
        return (*this);
    }
    Fraction determinant = findDet();
    if ( determinant == Fraction(Bignum("0"), Bignum("0")) ) {
        std::cout << "No Inverse matrix can be found since Det == 0" << std::endl;
        return (*this);
    }
    Matrix minorMat = findMinorMat();
//    std::cout << "MInorMAt: " << minorMat << std::endl;
//    std::cout << "MInorMAtLENG: " << minorMat.length << std::endl;
    for (int i = 0; i < minorMat.matrix.size(); ++i) {
        if(minorMat.length == 3) {
            if(i % 2 != 0) minorMat.matrix[i] = -minorMat.matrix[i];
        }
    }
    if(minorMat.length == 2) {
        minorMat.matrix[1] = -minorMat.matrix[1];
        minorMat.matrix[2] = -minorMat.matrix[2];
    }
//    std::cout << "MInorMAt after: " << minorMat << std::endl;
    Matrix transposedMat = minorMat.transposeMat();
//    std::cout << "Det: " << (Fraction(Bignum("1"), Bignum("1")) / determinant) << std::endl;
//    std::cout << "Tans: " << transposedMat << std::endl;

    Matrix result(*this);
    for (int j = 0; j < transposedMat.matrix.size(); ++j) {
        result.matrix[j] = (Fraction(Bignum("1"), Bignum("1")) / determinant) * transposedMat.matrix[j];
//        Fraction temp = (Fraction(Bignum("1"), Bignum("1")) / determinant) * transposedMat.matrix[j];
//        std::cout << "Leaving For on j:" << j << std::endl;
//        result.matrix[j] = Fraction(temp.getNumerator(), temp.getDenominator());
    }
    return result;
}

Fraction Matrix::findDet() {
    Fraction determinant(Bignum("0"), Bignum("0"));
    if (length == 2) {
        Fraction ad = (matrix[0] * matrix[3]);
        Fraction bc = (matrix[1] * matrix[2]);
        determinant = ad - bc;
    } else if (length == 3) {
        //|A| = a(ei − fh) − b(di − fg) + c(dh − eg)
        // A B C
        //D E F
        //G H I
        Fraction ei = matrix[4] * matrix[8];
        Fraction fh = matrix[5] * matrix[7];
        Fraction di = matrix[3] * matrix[8];
        Fraction fg = matrix[5] * matrix[6];
        Fraction dh = matrix[3] * matrix[7];
        Fraction eg = matrix[4] * matrix[6];
        Fraction a = (matrix[0] * (ei - fh));
        Fraction b = (matrix[1] * (di - fg));
        Fraction c = (matrix[2] * (dh - eg));
        determinant = a - b + c;
    } else {
        //big
    }
    return determinant;
}

Matrix Matrix::findMinorMat() {
    Matrix minorMat;
    if(length == 2) {
        minorMat = Matrix(2, 2);
        minorMat.matrix[0] = matrix[3];
        minorMat.matrix[1] = matrix[2];
        minorMat.matrix[2] = matrix[1];
        minorMat.matrix[3] = matrix[0];
    } else if(length == 3) {
        //0 1 2
        //3 4 5
        //6 7 8
        minorMat = Matrix(3, 3);
        minorMat.matrix[0] = findDet(matrix[4], matrix[5], matrix[7], matrix[8]);
        minorMat.matrix[1] = findDet(matrix[3], matrix[5], matrix[6], matrix[8]);
        minorMat.matrix[2] = findDet(matrix[3], matrix[4], matrix[6], matrix[7]);
        minorMat.matrix[3] = findDet(matrix[1], matrix[2], matrix[7], matrix[8]);
        minorMat.matrix[4] = findDet(matrix[0], matrix[2], matrix[6], matrix[8]);
        minorMat.matrix[5] = findDet(matrix[0], matrix[1], matrix[6], matrix[7]);
        minorMat.matrix[6] = findDet(matrix[1], matrix[2], matrix[4], matrix[5]);
        minorMat.matrix[7] = findDet(matrix[0], matrix[2], matrix[3], matrix[5]);
        minorMat.matrix[8] = findDet(matrix[0], matrix[1], matrix[3], matrix[4]);
    }
    return minorMat;
}

Fraction Matrix::findDet(Fraction a, Fraction b, Fraction c, Fraction d) {
    Matrix temp = Matrix(2, 2);
    temp.matrix[0] = a;
    temp.matrix[1] = b;
    temp.matrix[2] = c;
    temp.matrix[3] = d;
    Fraction det =  temp.findDet();
    return det;
}

Matrix Matrix::transposeMat() {
    Matrix temp(*this);
    if(length == 2) {
        temp.matrix[0] = matrix[0];
        temp.matrix[2] = matrix[1];
        temp.matrix[1] = matrix[2];
        temp.matrix[3] = matrix[3];
    } else if(length == 3) {
        temp.matrix[0] = matrix[0];
        temp.matrix[3] = matrix[1];
        temp.matrix[6] = matrix[2];
        temp.matrix[1] = matrix[3];
        temp.matrix[4] = matrix[4];
        temp.matrix[7] = matrix[5];
        temp.matrix[2] = matrix[6];
        temp.matrix[5] = matrix[7];
        temp.matrix[8] = matrix[8];
    }
    return temp;
}



//int Det(int **matr, int n) {
//    int temp = 0;   //временная переменная для хранения определителя
//    int k = 1;      //степень
//    if(n < 1){
//        std::cout<<"Не верный размер матрицы!!!" << std::endl;
//        return 0;
//    }
//    else if (n == 1)
//        temp = matr[0][0];
//    else if (n == 2)
//        temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];
//    else{
//        for(int i = 0; i < n; i++){
//            int m = n - 1;
//            int **temp_matr = new int * [m];
//            for(int j = 0; j < m; j++)h
//                temp_matr[j] = new int [m];
//            Get_matr(matr, n, temp_matr, 0, i);
//            temp = temp + k * matr[0][i] * Det(temp_matr, m);
//            k = -k;
//            FreeMem(temp_matr, m);
//        }
//    }
//    return temp;
//}