//
// Created by Jacob Yeung on 10/18/23.
//
//Specification file complexType.h

#ifndef H_complexNumber
#define H_complexNumber

#include <iostream>

using namespace std;

class complexType
{
    // overload stream insertion and extraction operators
    friend ostream& operator<< (ostream&, const complexType&);
    friend istream& operator>> (istream&, complexType&);

public:
    void setComplex(const double& real, const double& imag);
    //set the complex number according to the parameters
    //Postcondition: realPart = real; imaginaryPart = imag

    void getComplex(double& real, double& imag) const;
    //Function to retrieve the complex number.
    //Postcondition: real = realPart; imag = imaginaryPart

    complexType(double real = 0, double imag = 0);
    //Constructor
    //Initialize the complex number according to the parameters
    //Postcondition: realPart = real; imaginaryPart = imag

    complexType operator+(const complexType& otherComplex) const;
    complexType operator-(const complexType& otherComplex) const;
    //overload +
    complexType operator*(const complexType& otherComplex) const;
    complexType operator/(const complexType& otherComplex) const;
    //overload *
    //overload -
    //overload /

    bool operator==(const complexType& otherComplex) const;
    //overload ==

private:
    double realPart;      // variable to store the real part
    double imaginaryPart; // variable to store the imaginary part
};

#endif

//#ifndef CS216PROGRAMMINGEXERCISE1307_COMPLEXTYPE_H
//#define CS216PROGRAMMINGEXERCISE1307_COMPLEXTYPE_H
//
//
//class complexType {
//
//};
//
//
//#endif //CS216PROGRAMMINGEXERCISE1307_COMPLEXTYPE_H
