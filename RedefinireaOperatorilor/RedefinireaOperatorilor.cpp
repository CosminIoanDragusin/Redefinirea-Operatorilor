// RedefinireaOperatorilor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include <stdio.h>
using namespace std;

class complex
{
public:
    double real;
    double imag;
    complex(double re, double im) { real = re; imag = im; }
    complex() { real = 0; imag = 0; };
    complex operator+(complex arg)
    {
        complex rez;
        rez.real = real + arg.real; // rez.real=this->real+arg.real
        rez.imag = imag + arg.imag; // rez.imag=this->imag+arg.imag
        return rez;
    }

    complex operator-(complex arg) {
        complex rez;
        rez.real = real - arg.real;
        rez.imag = imag - arg.imag;
        return rez;
    }

    friend complex operator*(complex arg1, complex  arg2) {
        complex rez;
        rez.real = (arg1.real * arg2.real - arg1.imag * arg2.imag);
        rez.imag = (arg1.real * arg2.imag + arg2.real* arg1.imag);
        return rez;
    }

    complex operator++() {
        complex rez;
        rez.real = real + 1; 
        rez.imag = imag ; 
        return rez;
    }

    complex operator++(int arg) {
        complex rez;
        rez.real = real + arg;
        rez.imag = imag; 
        return rez;
    }

    void afisare_complex() {
        cout << "Numarul complex: " << real << " + " << imag <<"i" << endl;
        //cout << "Partea imaginara a numarului complex este : " << imag << endl;
    }
};



int main()
{
    complex c1(1, 2), c2(5, 7), c3, c4, c5, c6, c7, c8;
    complex ex1(2, 3), ex2(4, 5), ex3(6, 7), ex4(8, 9);
    complex unar1, unar2;
    c1.afisare_complex();
    c2.afisare_complex();
   
    //printf("\nc1 ( %lf , %lf )", c1.real, c1.imag);
    //printf("\nc2 ( %lf , %lf )", c2.real, c2.imag);


    c3 = c1 + c2; // asta ne interesa !!!
    c3.afisare_complex();
    //printf("\nc3 ( %lf , %lf )", c3.real, c3.imag);

    c4 = c1.operator+(c2);
    c4.afisare_complex();

    c5 = c1 + c2 + c3;
    c5.afisare_complex();

    c6 = c2 - c1;
    c6.afisare_complex();

    c7 = c1 * c2;
    c7.afisare_complex();

    c8 = ex1 + ex2 - ex3 * ex4;
    c8.afisare_complex();

    unar1 = ++c1;
    unar1.afisare_complex();

    unar2 = c1++;
    unar2.afisare_complex();
}

