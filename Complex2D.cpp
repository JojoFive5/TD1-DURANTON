#include "Complex2D.h"

Complex2D::Complex2D():re(0), img(0), phi(0), mod(0)
{}

Complex2D::Complex2D(double real, double imaginary):re(real), img(imaginary) {
    phi = atan(img/re);
    mod = sqrt(pow(re, 2) + pow(img, 2));
}

Complex2D::Complex2D(double ri):re(ri), img(ri) {
    phi = atan(1);
    mod = abs(ri);
}

Complex2D::Complex2D(Complex2D const &c):re(c.re), img(c.img), phi(c.phi), mod(c.mod)
{}

void Complex2D::setRe(double real) {
    re = real;
    phi = atan(img/re);
    mod = sqrt(pow(re, 2) + pow(img, 2));
}

void Complex2D::setImg(double imaginary) {
    img = imaginary;
    phi = atan(img/re);
    mod = sqrt(pow(re, 2) + pow(img, 2));
}

double Complex2D::getRe() const {
    return re;
}

double Complex2D::getImg() const {
    return img;
}

double Complex2D::getMod() const {
    return mod;
}

double Complex2D::getPhi() const {
    return phi;
}

Complex2D Complex2D::getConjugate() const {
    return Complex2D(re, -img);
}

Complex2D Complex2D::getInverse() const {
    return (1/pow(mod,2))*getConjugate();
}

Complex2D Complex2D::getRotated(double angle) {
    double new_angle = phi + angle;
    return mod*Complex2D(cos(new_angle), sin(new_angle));
}

Complex2D operator + (Complex2D const &a, const Complex2D &b) {
    return Complex2D(a.re + b.re, a.img + b.img);
}

Complex2D operator - (Complex2D const &a, const Complex2D &b) {
    return Complex2D(a.re - b.re, a.img - b.img);
}

Complex2D operator * (Complex2D const &a, const Complex2D &b) {
    return Complex2D((a.re*b.re - a.img*b.img), (a.re*b.img + a.img*b.re));
}

Complex2D operator * (double const d, const Complex2D &a) {
    return Complex2D(d*a.re, d*a.img);
}

Complex2D operator / (Complex2D const &a, const Complex2D &b) {
    return a*b.getInverse();
}

bool operator < (Complex2D const &a, const Complex2D &b) {
    return a.mod < b.mod;
}

bool operator > (Complex2D const &a, const Complex2D &b) {
    return a.mod > b.mod;
}

string Complex2D::to_string() const {
    string separator = (img < 0) ? " - " : " + ";
    return std::to_string(re) + separator + std::to_string(abs(img)) + "·i";
}

void Complex2D::printAllInfo() const {
    string phi_str = std::to_string(phi);
    string mod_str = std::to_string(mod);

    cout << to_string() << endl
         << "Phi : " << phi_str << endl
         << "Mod : " << mod_str << endl;
}

ostream& Complex2D::printOn (ostream& os) const {
    os << to_string() << endl;
    return os;
}

ostream& Complex2D::printAllInfoOn (ostream& os) const {
    string phi_str = std::to_string(phi);
    string mod_str = std::to_string(mod);

    os << to_string() << endl
       << "Phi : " << phi_str << endl
       << "Mod : " << mod_str << endl;
    return os;
}