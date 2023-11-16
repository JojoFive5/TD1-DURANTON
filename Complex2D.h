#ifndef COMPLEX2D_H
#define COMPLEX2D_H

#include <iostream>
#include <cmath>
using namespace std;

class Complex2D {

    /*Data members*/

    private:
        double re;
        double img;
        double phi;
        double mod;
    /* Constructors*/
    public:
        Complex2D();
        Complex2D(double, double);
        Complex2D(double);
        Complex2D(Complex2D const&);

        /* Set and get*/

        void setRe(double);
        void setImg(double);
        double getRe() const;
        double getImg() const;
        double getMod() const;
        double getPhi() const;
        
        /* specials methodes for Complex*/

        Complex2D getConjugate() const;
        Complex2D getInverse() const;
        Complex2D getRotated(double angle);

        /*Operators*/

        friend Complex2D operator + (const Complex2D &a, const Complex2D &b);
        friend Complex2D operator - (Complex2D const &a, Complex2D const &b);
        friend Complex2D operator * (Complex2D const &a, Complex2D const &b);
        friend Complex2D operator * (double const d, const Complex2D &a);
        friend Complex2D operator / (Complex2D const &a, Complex2D const &b);
        friend bool      operator < (Complex2D const &a, Complex2D const &b);
        friend bool      operator > (Complex2D const &a, Complex2D const &b);
        
        
        /* function to display and get informations*/


        string to_string() const;
        void printAllInfo() const;
        ostream& printOn(ostream&) const;
        ostream& printAllInfoOn(ostream&) const;
};

#endif