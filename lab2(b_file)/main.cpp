#include <iostream>
#include "header.h"
using namespace std;
int main(){
    string fileName1 = "File1.dat";
    string fileName2 = "File2.dat";
    string fileName3 = "m.dat";
    cout <<fileName1 <<":"<<endl;
    getLines(fileName1);
    vector<Ampoule> info = file_text(fileName1);
    cout <<fileName2 <<":"<<endl;
    secondFileLines(fileName2 ,info);
    cout <<fileName1<<":\n";
    outFIle(fileName1);
    cout <<fileName2<<":\n";
    outFIle2(fileName2);
    deleteAmpule(fileName2 ,fileName3);
    cout <<"Modified file 2 :"<<endl;
    outFIle2(fileName2);
}