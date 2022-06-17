#pragma once
#include "VectorR3.h"
#include "VectorR2.h"
#include "VectorClass.h"
#include <iostream>
#include <string>
#include <vector>
TVectorR2* inputVectorR2();
TVectorR3* inputVectorR3();
double valNumber();
bool isNumber(string s);
void create_arr(vector<TVector *> & arr , int n,int m );
double sum_of_Paralel(vector<TVector *> arr , int n , vector<TVector *> & paral);
double sum_of_Perpen(vector<TVector *> arr , int n, int m ,  vector<TVector *>  &perpen);
void out_All(vector<TVector *> arr , int n ,int  m);
void out_to_zero(vector<TVector *> arr , string text);