#include "foo.h"
void inputHexNUmber(Numeral_16 & obj1 , Numeral_16 & obj2 , Numeral_16 &obj3){//створюємо конструктор
    string hex_n;
    cout << "Enter hex number for 1 item :"<<endl;
    cin >> hex_n;
    hex_n = verHex( hex_n);
    obj1 = Numeral_16(hex_n);
    obj2 = Numeral_16(obj1);
    obj3 = Numeral_16();


}
string verHex(string number){// check if it is number in 16(hex)

    while (!valHexs(number)){
        cout <<"Enter correct hex number :"<<endl;
        cin >> number;
    }
    cin.ignore();
    return number;
}
bool valHexs(string number){//check char
    bool flag = false;
    for (int i=0; i<number.length(); i++)
    {
        if (!isxdigit(number[i]))
        {
            return flag;
        }
    }
    return true;
}
void AllPrint(Numeral_16  obj1 , Numeral_16  obj2 , Numeral_16 obj3){// print all
    cout <<"First  (1)  :";obj1.print();
    cout <<"Second (2)  :";obj2.print();
    cout <<"Third  (3)  :";obj3.print();

}
int inputNum(){// Enter add number
    string n;
    cout <<"How much do you want to increase N2? :"<<endl;
    cin >> n;
    while (!isNumber(n) || stoi(n) <=0){
        cout <<"Enter correct number :"<<endl;
        cin >> n;
    }
    return stoi(n);
}
bool isNumber(string s)// check if it is int number
{
    for (char ch : s) {
        if (!isdigit(ch)) return false;
    }

    return true;
}
//