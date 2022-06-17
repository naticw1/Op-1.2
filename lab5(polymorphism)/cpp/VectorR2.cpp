
#include "VectorR2.h"

TVectorR2::TVectorR2(double x, double y): TVector(x)
{
    this->y = y;
}
bool TVectorR2::isParal(TVector *obj) {
    double tmp = x * ((TVectorR2*)obj)->y - y * obj->x;
    return !tmp;
}
bool TVectorR2::isPerpen(TVector *obj) {
    double tmp = x *obj->x + y * ((TVectorR2 *)obj)->y;
return !tmp;
}

double TVectorR2::vectorLen() {
    return sqrt(x*x + y*y);
}
void TVectorR2::print() {
    TVector::print();
    cout <<" Y = "<<y<<endl;
}


