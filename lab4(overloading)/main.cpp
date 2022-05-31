#include "foo.h"
int main (){
    Numeral_16 N1 , N2 , N3;
    inputHexNUmber(N1 , N2 , N3);
    AllPrint(N1 , N2 , N3);
    int number_to;
    number_to = inputNum();
    N1++;
    N2 += number_to;
    N3 = N1 + N2;
    cout <<"----------After changing------------"<<endl;
    AllPrint(N1 , N2 , N3);
    cout <<"\nHexadecimal to Decimal (N3) :"<<(N3.convertHex())<<endl;
}
