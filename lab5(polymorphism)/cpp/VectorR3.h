#pragma once
#include "VectorClass.h"
#include <cmath>
class TVectorR3 :public TVector
{
    double y;
    double z;
public:
    TVectorR3(double x , double y , double z);
    void print() override;
    bool isPerpen(TVector * obj) override;
    bool isParal(TVector * obj) override;
    double vectorLen() override;


};