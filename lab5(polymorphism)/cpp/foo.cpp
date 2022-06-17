#include "foo.h"
TVectorR2* inputVectorR2(){

    double x , y;
    cout <<"Enter x:"<<endl;
    //cin >> x;
    x = valNumber();
    cout <<"Enter y:"<<endl;
    y = valNumber();
    TVectorR2 * tmp = new TVectorR2(x ,y);
    return tmp;
}
TVectorR3* inputVectorR3(){

    double x , y ,z;
    cout <<"Enter x:"<<endl;
    x = valNumber();
    cout <<"Enter y:"<<endl;
    y = valNumber();
    cout <<"Enter z:"<<endl;
    z = valNumber();
    TVectorR3 * tmp = new TVectorR3(x ,y ,z);
    return tmp;
}
double valNumber(){// Enter add number
    string n;
    cin >> n;

    while (!isNumber(n) ){
        cout <<"Enter correct number :"<<endl;
        cin >> n;
    }
    return stod(n);
}
bool isNumber(string s)// check if it is int number
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

void create_arr(vector<TVector *> & arr , int n,int m ){
    cout << "Enter cootdinate for vector R^2 :"<<endl;
    for (int i = 0 ;i < n;i++){
        arr.push_back(inputVectorR2());
    }
    cout << "Enter cootdinate for vector R^3( x, y , z) :"<<endl;
    for (int i = 0 ;i < m;i++){
        arr.push_back(inputVectorR3());
    }

}
double sum_of_Paralel(vector<TVector *> arr , int n , vector<TVector *> & paral){
    double sum = 0;

    for (int i = 1 ;i < n;i++){
        if (arr[0]->isParal(arr[i])){
            sum += arr[i]->vectorLen();
            paral.push_back(arr[i]);
        }
    }
    return sum;
}
double sum_of_Perpen(vector<TVector *> arr ,int n, int m ,  vector<TVector *>  &perpen){
    double sum = 0;
    for (int i = 1 + n; i < m +n; i++){
        if (arr[n]->isPerpen(arr[i])){
            sum += arr[i]->vectorLen();
            perpen.push_back(arr[i]);
        }
    }
    return sum;
}
void out_All(vector<TVector *> arr , int n ,int  m){
    cout << "Vectors R^2 :"<<endl;
    for (int i = 0; i < n; i++){
        arr[i]->print();
    }
    cout <<"Vectors R^3 :"<<endl;
    for(int i = n ; i < m+n; i++){
        arr[i]->print();
    }
}
void out_to_zero(vector<TVector *> arr , string text){
    cout <<text<<endl;
    for (int i = 0; i < arr.size(); i++){
        arr[i]->print();
    }
}
