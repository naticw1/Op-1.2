#pragma once
#include <iostream>
using namespace std;
class TVector{
    double x;
public:

    TVector(int x);

    virtual bool isParal(TVector * obj) = 0;
    virtual bool isPerpen(TVector * obj) = 0;
    virtual double vectorLen() = 0;
    virtual void print();
    friend class TVectorR2;
    friend class TVectorR3;
};