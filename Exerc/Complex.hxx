//
// Created by ys on 19-6-17.
//

#ifndef CMAKEQT_COMPLEX_HXX
#define CMAKEQT_COMPLEX_HXX

#include <iostream>

class Complex
{
    double Real, Imag;
public:

    Complex(double r = 0, double i = 0) : Real(r), Imag(i){}

    double getReal() const
    {
        return Real;
    }

    double getImag() const
    {
        return Imag;
    }

    Complex operator + (Complex &c);
    Complex operator + (double d);
    Complex &operator = (Complex c);
    void show()
    {
        std::cout << Real << " + j" << Imag << std::endl;
    }

};


void testComplex()
{
    Complex c1(3, 4), c2(5, 6), c3;
    c1.show();
    c2.show();
    c3 = c1 + c2;
    c3.show();
    c3 = c3 + 6.5;
    c3.show();
    c3 + 2;
    c3.show();
}
#endif //CMAKEQT_COMPLEX_HXX
