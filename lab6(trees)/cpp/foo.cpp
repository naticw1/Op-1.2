#include "foo.h"
void addElemnts(Tree & tree , int size){
    cout << "Enter elements :"<<endl;
    double element;
    for (int i = 0 ; i < size; i++){
        element = valNumber();
        tree.addEle(element);
    }
}
double valNumber(){// Enter number of elements
    string n;
    cout <<"Elem :";
    cin >> n;

    while (!isFloatNumber(n) ){
        cout <<"Enter correct number :"<<endl;
        cin >> n;
    }
    return stod(n);
}
bool isFloatNumber(string s)// check if it is float number
{
    int count = 0;
    for (char ch : s) {
        if (ch =='.'){
            count ++;
            if(count > 1){
                return false;
            }
        }
        else if (!isdigit(ch) && ch != '-') return false;
    }

    return true;
}
int inputNumber(){
    string n;
    cout << "Enter number of elements :"<<endl;
    cin >>n;
    while (!isNumber(n) || stoi(n) < 1){
        cout <<"Enter correct number of elements :";
        cin >>n;
    }
    return stoi(n);
}
bool isNumber(string s)// check if it is int number
{
    for (char ch : s) {
        if (!isdigit(ch) ) return false;
    }

    return true;
}


