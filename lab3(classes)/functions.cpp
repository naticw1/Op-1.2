#include "functions.h"
#include "cone.h"
int inputSize(){
    int n;
    cout <<"Enter number of cones :\n ";
    cin >> n;
    cin.ignore();
    while (n < 1 ){
        cout <<"Enter the correct number of cones :"<<endl;
        cin >> n;
    }
    return n;
}
double inputCoo(){
    string c;
    cin >>c;
    cin.ignore();
    /*while (isdigit(c) == 0 ){
        cout <<"Enter the correct  :";
        cin >> c;
    }*/
    bool flag = verCoo(c);
    while (flag == false){
        cout <<"Enter the correct  :";
        cin >> c;
        cin.ignore();
        flag = verCoo(c);
    }

    return stod(c);
}
bool isNumb(const string& str){
    for (char const &c : str){
        if (isdigit(c) == 0)return false;
    }
    return true;

}

bool verCoo(string str){
    bool flag = false;
    for (int i = 0; i < str.size(); i ++){
        if (str[i] == '.') {
            string bef = str.substr(0, i);
            string aft = str.substr(i, str.size()+1);
            if (isNumb(bef) && isNumb(aft)){
                flag = false;
            }
            else {
                flag = true ;
            }

        }

    }
    return flag;
}
Cone * input(int size){
    Cone * cones = new Cone[size];
    for (int i = 0; i < size; i++){
        cout <<"Cone "<<i+1<<":"<<endl;
        Point points[2];
        for (int j = 0; j < 2; j ++){
            if (j == 0){
                cout <<"Point O(center of foundation) :\n";
            }
            else{
                cout <<"Point A(the top of the cone) :\n";
            }
            cout <<"Enter x coordinate : \n";
            double x = inputCoo();
            cout <<"Enter y coordinate : \n";
            double y = inputCoo();
            cout <<"Enter z coordinate : \n";
            double z = inputCoo();
            points[j] = Point(x,y,z);
        }
        cout <<"Enter the radius of the base of the cone :\n";
        double r = inputCoo();
        cones[i] = Cone(points , r);
    }
    return cones;
}
int getINdex(Cone * cones , int size){
    int index;
    for (int i = 1; i < size; i++){
        if (cones[i].getGenerator() > cones[0].getGenerator()){
            index = i;
        }
    }
    return index;
}
void outAllCones(Cone* cones ,int size){
    cout <<"All cones :"<<endl;
    for (int i = 0; i < size; i++){
        cout <<"Cone "<<i + 1<<":"<<endl;
        cones[i].out();
    }
}
void outMax(Cone* cones , int max){
    cout <<"Max generator have this cone : ("<<max + 1<<") :"<<endl;
    cones[max].out();
}


