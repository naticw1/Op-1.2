#include "hex_numb.h"
Numeral_16::Numeral_16() {}
Numeral_16::Numeral_16(string hex_) {
    this->hex_= hex_;
}
Numeral_16::Numeral_16(const Numeral_16 &obj) {
    hex_ = obj.hex_;
}

void Numeral_16::setHex(string hex_) {
    this->hex_=hex_;
}

string Numeral_16::getHex() {
    return this->hex_;
}

string Numeral_16::convertHex() {// convert from 16 to 10 (last task)
    int mul = 1;//mul is 16 * position
    int dec_val = 0;
    for (int i = hex_.length() - 1; i >= 0; i--) {
        if (hex_[i] >= '0' && hex_[i] <= '9') {
            dec_val += (int(hex_[i]) - 48) * mul;//convert from chat '0' - '9' to number 0 - 9
            mul = mul * 16;
        }
        else if (hex_[i] >= 'A' && hex_[i] <= 'F') {//convert from chat 'A' - 'F' to number 10 - 15
            dec_val += (int(hex_[i]) - 55) * mul;
            mul = mul * 16;
        }
    }
    return to_string(dec_val);

}
string Numeral_16::hexAdd(string hex1, string hex2)//add to numbers
{
    if (hex1.length() < hex2.length()) {
        hex1.swap(hex2);//check if hex 1 < hex2 to make loop
    }

    int length1, length2;
    length1 = hex1.length();
    length2 = hex2.length();
    int flag = 0;
    int get1, get2;
    int sum;

    while (length1>0)
    {
        // first
        if (hex1[length1 - 1] >= 'A') {
            get1 = hex1[length1 - 1] - 55;
        }
        else {
            get1 = hex1[length1 - 1] - '0';
        }
        //second

        if (length2 > 0)
        {
            if (hex2[length2 - 1] >= 'A') {
                get2 = hex2[length2 - 1] - 55;
            }
            else {
                get2 = hex2[length2 - 1] - '0';//48
            }
        }
        else {
            get2 = 0;
        }

        //sum of all ( 1 + 2 +..)
        sum = get1 + get2 + flag;

        if (sum >= 16)
        {
            int left = sum % 16;
            if (left >= 10) {
                hex1[length1 - 1] = 'A' + left % 10;
            }
            else {
                hex1[length1 - 1] = '0' + left;
            }
            flag = 1;
        }
        else
        {
            if (sum >= 10) {
                hex1[length1 - 1] = 'A' + sum % 10;
            }
            else {
                hex1[length1 - 1] = '0' + sum;
            }
            flag = 0;
        }

        length1--;
        length2--;
    }

    if (flag == 1) {
        return "1" + hex1;
    }
    else {
        return hex1;
    }
}

Numeral_16 Numeral_16::operator++(int) {
    toAdd++;
    hex_ = hexAdd(hex_ , to_string(toAdd));
    return *this;

}


Numeral_16  Numeral_16::operator+(const Numeral_16 obj) {
    string d1 = this->hexAdd(hex_ , obj.hex_);
    Numeral_16 test = Numeral_16(d1);
    return test;
}
Numeral_16 Numeral_16::operator+=(int const number) {
    hex_ = hexAdd(hex_ , to_string(number));
    return *this;
}
