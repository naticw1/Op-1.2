#include "VectorR3.h"

TVectorR3::TVectorR3(double x, double y , double z): TVector(x)
{
    this->y = y;
    this->z = z;
}
bool TVectorR3::isParal(TVector *obj) {
    double tmp = (y * ((TVectorR3*)obj)->z - ((TVectorR3*)obj)->y * z) - (x * ((TVectorR3*)obj)->z - obj->x * z) + (x * ((TVectorR3*)obj)->y - obj->x * y);
    return !tmp;
}
bool TVectorR3::isPerpen(TVector *obj) {
    double tmp = x * obj->x + y * ((TVectorR3*)obj)->y + z * ((TVectorR3*)obj)->z;
    return !tmp;
}

double TVectorR3::vectorLen() {
    return sqrt(x*x + y*y + z*z);
}
void TVectorR3::print() {
    TVector::print();
    cout <<" Y = "<<y;
    cout << " Z = "<<z<<endl;
}
