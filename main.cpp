//DONE// Write correct division and remainder functions and multiplication
//DONE// Write reverse matrix calculator
//DONE// Write 4 basic operations in short form
//this - func obj or left operand?

#include <iostream>
#include <vector>
#include <string>
#include "Bignum.h"
#include "Fraction.h"
#include "Matrix.h"
#include "Exception.h"
#include "InputException.h"
#include "MathException.h"
#include "DivideByZeroException.h"

void fillMatrix(Matrix &mat);

using namespace std;
int main() {
    try {
//        Bignum a = Bignum("q");//Input Exception
//        Fraction b(Bignum("1"), Bignum("0"));//MathException - DivideByZeroException
        while (true) {
            try {
                Matrix c(1,1);
                fillMatrix(c);
                break;
            } catch (InputException<std::string> &e) {
                cout << "Error: " << e.what() << ": " << e.getInput() << endl;
                cout << "Now do it again, PROPERLY this time!" << endl;
            }
        }
    } catch (InputException<std::string> &e) {
        cout << "Error: " << e.what() << ": " << e.getInput() << endl;
    } catch (DivideByZeroException<int> &e) {
        cout << "Error: " << e.what() << ": " << e.getError() << " with first operand being: " << e.showFirstOperand() << endl;
    } catch (MathException<int> &e) {
        cout << "Error: " << e.what() << ": " << e.getError() << endl;
    } catch (Exception &e) {
        cout << "Error: " << '9' - 48 <<e.what() << endl;
    } catch (...) {
        cout << "Unknown error" << endl;
    };

    cout << "That's all folks!" << endl;

//    try {
//        Matrix matr(1,1);
//        fillMatrix(matr);
//    } catch (InputException &e) {
//        cout << "Error: " << e.what() << ": " << e.getInput() << endl;
//    }


//    Bignum a = (string)"60";
//    cout << "Bignum a: " << a << endl;
//    Bignum b = (string)"10";
//    cout << "Bignum b: " << b << endl;
//    cout << "a + b: " << a + b << endl;
//    cout << "a - b: " << a - b << endl;
//    cout << "a * b: " << a * b << endl;
//    cout << "a / b: " << a / b << endl;
//
//
//    Fraction fr(Bignum("1"), Bignum("2"));
//    cout << "Fraction fr:" << fr << endl;
//    Fraction fra(Bignum("4"), Bignum("2"));
//    cout << "Fraction fra:" << fra << endl;
//    cout << "fr * fra:" << fr * fra << endl;
//
//
//    Matrix m(2, 2);
//    fillMatrix(m);
//    cout << m << endl;
//    Matrix mat = !m;
//    cout << "!m:" << endl;
//    cout << mat << endl;
//    Matrix ma = m + 2;
//    cout << "m + 2: " << ma << endl;
    return 0;
}

void fillMatrix(Matrix &mat) {
    int Y = 1;
    int X = 1;
//    std::cout << "LENFTT " << mat.length << std::endl;
    for (auto &i : mat.matrix) {
        std::cout << "Element " << Y << ", " << X << ": ";
        std::string temp;
        std::getline(std::cin, temp);
        std::string::size_type pos = temp.find('/');
        if(pos == std::string::npos)
            throw InputException<std::string>("Wrong input", temp);
//            return fillMatrix(mat); //std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
        std::string denom = temp.substr(pos+1);
//        std::cout << "Denom: " << denom << std::endl;
        temp.erase(pos);
        std::string numer = temp;
        i = Fraction(Bignum(numer), Bignum(denom));
        if(X%mat.length == 0) {
            X = 1;
            Y++;
        } else X++;
    }
}