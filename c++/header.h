#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int numberN();
vector<string> inp_lines();
void text_to_file(string name ,vector<string> lines);
void splitting (vector<string>lines,vector<string> & lines1 , vector<string> & lines2);
void odd_number(vector<string> &lines1);
void even_number_task(vector<string> &lines2 , int n);
vector <string> splitF (string s);
vector <string> sort_words(vector <string> words );
string convertVectorToString(vector<string> words);
void outFileText(string name);


