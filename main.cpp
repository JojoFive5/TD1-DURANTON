#include <iostream>
#include <cmath>
using namespace std;

#include "Complex2D.h"

int main() {
    Complex2D z1(2, 3);
    Complex2D z2(3, 4);

    cout << "z1  = ";
    z1.printAllInfo();
    cout << endl;
    cout << "z2 = ";
    z2.printAllInfo();
    cout << endl;

    // Testing the methods

    cout << "z1.getConjugate()" << endl;
    z1.getConjugate().printAllInfo();
    cout << endl;

    cout << "z1.getInverse()" << endl;
    z1.getInverse().printAllInfo();
    cout << endl;

    cout << "z1.getRotated(pi/4)" << endl;
    z1.getRotated(M_PI/4).printAllInfo();
    cout << endl;

    cout << "z1 + z2" << endl;
    (z1+ z2).printAllInfo();
    cout << endl;

    cout << "z1 - z2" << endl;
    (z1 - z2).printAllInfo();
    cout << endl;

    cout << "z1 * z2" << endl;
    (z1 * z2).printAllInfo();
    cout << endl;

    cout << "z1 / z2" << endl;
    (z1 / z2).printAllInfo();
    cout << endl;

    cout << "z1 < z2 (compare abs values)" << endl;
    cout << to_string(z1 < z2) << endl;
    cout << endl;
    
    cout << "z1 > z2 (compare abs values)" << endl;
    cout << to_string(z1 > z2) << endl;
    cout << endl;
    
    return 0;
}