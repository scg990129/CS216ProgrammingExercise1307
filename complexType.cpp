//
// Created by Jacob Yeung on 10/18/23.
//

//Implementation file complexType.cpp

#include <iostream>
#include "complexType.h"

using namespace std;

ostream& operator<< (ostream& os, const complexType& complex)
{
    os << "(" << complex.realPart << ", "
       << complex.imaginaryPart << ")";
    return os;
}

istream& operator>> (istream& is, complexType& complex)
{
    char ch;

    is >> ch;                     //read and discard (
    is >> complex.realPart;       //get the real part
    is >> ch;                     //read and discard,
    is >> complex.imaginaryPart;  //get the imaginary part
    is >> ch;                     //read and discard)

    return is;
}

bool complexType::operator==(const complexType& otherComplex) const
{
    return(realPart == otherComplex.realPart &&
           imaginaryPart == otherComplex.imaginaryPart);
}

//constructor
complexType::complexType(double real, double imag)
{
    realPart = real;
    imaginaryPart = imag;
}

void complexType::setComplex(const double& real, const double& imag)
{
    realPart = real;
    imaginaryPart = imag;
}

void complexType::getComplex(double& real, double& imag) const
{
    real = realPart;
    imag = imaginaryPart;
}

// If (a, b) and (c, d) are complex numbers: (a, b) - (c, d) = (a - c, b - d)
complexType complexType::operator-(const complexType& otherComplex) const {
    complexType temp(-1 * otherComplex.realPart, -1* otherComplex.imaginaryPart);

    return this->operator+(temp);
}

//If (c, d) is nonzero: (a, b)/(c, d) = ((ac + bd)/(c^2+d^2), (-ad + bc)/(c^2+d^2))
complexType complexType::operator/(const complexType& otherComplex) const{
    double real = this->realPart * otherComplex.realPart + this->imaginaryPart * otherComplex.imaginaryPart;
    double imag = -1 * this->realPart * otherComplex.imaginaryPart + this->imaginaryPart * otherComplex.realPart;

    double dominator = otherComplex.realPart * otherComplex.realPart + otherComplex.imaginaryPart * otherComplex.imaginaryPart;

    return {real/dominator, imag/dominator};
}

//overload the operator +
complexType complexType::operator+(const complexType& otherComplex) const
{
    complexType temp;

    temp.realPart = realPart + otherComplex.realPart;
    temp.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;

    return temp;
}

//overload the operator *
complexType complexType::operator*(const complexType& otherComplex) const
{
    complexType temp;

    temp.realPart = (realPart * otherComplex.realPart) -
                    (imaginaryPart*otherComplex.imaginaryPart);
    temp.imaginaryPart = (realPart * otherComplex.imaginaryPart) +
                         (imaginaryPart * otherComplex.realPart);
    return temp;
}

// overload the operator -

// overload the oeprator /

