#pragma once
#include <string>
//#include <ctype.h>
#include "cone.h"
using namespace std;
int inputSize();
double inputCoo();
bool verCoo(string str);
bool isNumb(const string& str);
Cone * input(int size);
int getINdex(Cone * cones , int size);
void outAllCones(Cone* cones ,int size);
void outMax(Cone* cones , int max);
