/*
 * @Author: tianxya
 * @Date: 2021-09-19 00:09:39
 * @LastEditTime: 2021-09-19 18:35:19
 * @LastEditors: Please set LastEditors
 * @Description: C++ basic learn 
 * @FilePath: /basic_learn/complex_test/src/complex/complex.h
 */
#ifndef COMPLEX_COMPLEX_H_
#define COMPLEX_COMPLEX_H_
#include <cmath>
#include <iostream>

template<typename T>
class Complex
{
private:
    T re,im;

public:
    /**
     * @description: inline function,it will run fast,but it depend on compiler
     * @description: initialztion list(构造函数独有的初始化方法)
     * @param {*}
     * @return {*}
     */
    Complex(T r=0,T i=0):re(r),im(i){}
    inline Complex& Complex&::operator += (const Complex& r){
        return __doap1(this,r);
    }

    /**
     * @description: const的使用:是非常有必要的,如果函数不改变值，最好加上const
     * @param {*}
     * @return {*}
     */
    T real () const {return re;}
    T imag () const {return im;}
private:
    inline Complex& __doap1(Complex* this,const Complex& r){
        this->re += r.re;
        this->imag += r.imag;
        return *this;
    }
};

#endif // !COMPLEX_COMPLEX_H_