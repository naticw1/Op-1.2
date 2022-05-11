#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
struct Ampoule{
    char name[21];
    char timeAfter[7];
    int expirationDate;

};
struct UsAmpule{
    char name [21];
    char timeOpening[7];
    char timeToUse[12];
};
void getLines(string filename1);
string verName(string name);
string verTimeAfter(string time);
bool verHour(string hours);
bool verMin(string minutes);
int verExpirationDate(int  date);
string getTime();
vector<Ampoule> file_text(string filename1);
void secondFileLines(string filename2, vector<Ampoule> info );
string checkInlist(vector<Ampoule> info, string name , int & number);
string getTimeToFile2(string timeFromFile1 , string timeOpening);
void outFIle(string filename1);
void outFIle2(string filename2);
void deleteAmpule(string filename2 , string filename3);

