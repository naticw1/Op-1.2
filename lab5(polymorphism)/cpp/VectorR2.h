#pragma once
#include "VectorClass.h"
#include <cmath>
class TVectorR2 :public TVector
{
    double y;
public:
    TVectorR2(double x , double y);
    void print() override;
    bool isPerpen(TVector * obj) override;
    bool isParal(TVector * obj) override;
    double vectorLen() override;


};