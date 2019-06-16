//
// Created by ys on 19-6-17.
//

#include "Complex.hxx"


Complex Complex::operator+(double d)
{
    Complex tmp;
    tmp.Real = Real + d;
    tmp.Imag = Imag;
    return tmp;
}



Complex Complex::operator+(Complex &c)
{
    Complex tmp;
    tmp.Real = Real + c.Real;
    tmp.Imag = Imag + c.Imag;
    return  tmp;
}


Complex &Complex::operator=(Complex c)
{
    Real = c.Real;
    Imag = c.Imag;
    return *this;
}
