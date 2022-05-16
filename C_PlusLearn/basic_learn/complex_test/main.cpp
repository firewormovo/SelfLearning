/*
 * @Author: your name
 * @Date: 2021-09-19 00:00:27
 * @LastEditTime: 2021-09-19 01:02:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /basic_learn/complex_test/main.cpp
 */
#include <iostream>
#include "complex/complex.h"

using namespace std;

int main(int argc,char** argv)
{
    Complex<double> c1(2.0,1.0);
    Complex<double>* p = new Complex<double>(4.0);
    const Complex<double> c2(3.0,4.0);
    Complex<double> c3;
    c3 += c2;
    
    cout << c1.real() << " " << c1.imag() << endl;
    cout << p->real() << " " << p->imag() << endl;
    cout << c2.real() << " " << c2.imag() << endl;
    cout << c3.real() << " " << c3.imag() << endl;
}