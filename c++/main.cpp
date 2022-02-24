#include <iostream>
#include "header.h"
using namespace std;

int main(){
    int n = numberN();
    cout <<"In the end of your text enter ctr + D\n";
    //Назви файлів
    string inFileName = "inputText.txt";
    string FileName1 = "text1.txt";
    string FileName2 = "text2.txt";
    string changed_FileName1 = "changed_text1.txt";
    string changed_FileName2 = "changed_text2.txt";
    //Вектор рядків
    vector<string> lines = inp_lines();
    text_to_file( inFileName , lines);
    vector <string> lines1;
    vector<string> lines2;
    //Розділення на два вектори
    splitting (lines, lines1 ,lines2);
    text_to_file(FileName1, lines1);
    text_to_file(FileName2, lines2);
    //завдання з не парними рядками
    odd_number(lines1);
    text_to_file(changed_FileName1, lines1);
    even_number_task(lines2 , n);
    //Запис змінених векторів у файл
    text_to_file(changed_FileName2, lines2);
    //Вивід даних з файлів
    cout <<"Original text :" << endl;
    outFileText(inFileName);
    cout <<"text 1 :" << endl;
    outFileText(FileName1 );
    cout <<"text 2 :" << endl;
    outFileText(FileName2 );
    cout <<"Changed text 1 :" << endl;
    outFileText(changed_FileName1 );
    cout <<"Changed text 2 :" << endl;
    outFileText(changed_FileName2 );
    return 0;
}
