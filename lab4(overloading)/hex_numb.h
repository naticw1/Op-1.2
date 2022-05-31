#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Numeral_16 {
    string hex_;
    int toAdd = 0;
public:
    Numeral_16();
    Numeral_16(string hex_);
    Numeral_16(const Numeral_16 & obj);
    void setHex(string hex_);
    string getHex();
    string convertHex();
    void print(){cout << "Your number is :\t"<<hex_<<endl;}
    string hexAdd(string nex1 , string next2);
    Numeral_16 operator++(int);
    Numeral_16 operator +(const Numeral_16  obj);
    Numeral_16 operator +=(const int number);


};
