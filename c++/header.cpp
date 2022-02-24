#include "header.h"
int numberN(){
    int n;
    cout << "enter N :";
    cin >> n;
    return n;
}
vector<string> inp_lines(){
    int combination = 94;
    string line ;
    vector<string> lines;
    while (int (line[0] != combination)){
        getline(cin , line);
        if (!line.empty()){
            lines.push_back(line);
        }
    }
    lines.pop_back();
    return lines;
}
void text_to_file(string name ,vector<string> lines){
    ofstream infile (name);
    for ( int i = 0; i < lines.size(); i++){
        infile << lines[i];
        if( i != lines.size()-1 ){
            infile <<"\n";
        }
    }
    infile.close();
}
void splitting (vector<string>lines,vector<string> & lines1 , vector<string> & lines2){
    for( int i = 0 ; i < lines.size(); i ++){
        if (i % 2 == 0){
            lines1.push_back(lines[i]);
        }
        else {
            lines2.push_back(lines[i]);
        }
    }
}
void odd_number(vector<string> &lines1){
    string tmp;
    for (int i = 0; i < lines1.size() ; i ++){
        for ( int j = i+1; j  < lines1.size() ; j ++){
            if (tolower(lines1[i][0]) > tolower(lines1[j][0]) && lines1[i][0] != ' '){
                tmp = lines1[i];
                lines1[i] = lines1[j];
                lines1[j] = tmp;
            }
            else if (tolower(lines1[i][0]) == tolower(lines1[j][0]) || lines1[j][0] == ' '){
                for (int k = 1; k  < lines1[i].size() ; k ++){
                    if (tolower(lines1[i][k]) > tolower(lines1[j][k]) || lines1[j][0] != ' ' && tolower(lines1[j][k]) < tolower(lines1[i][0])){
                        break;
                    }
                }
                tmp = lines1[i];
                lines1[i] = lines1[j];
                lines1[j] = tmp;
            }
        }
    }
}
void even_number_task(vector<string> &lines2 , int n){
    string tmp;
    for (int i = 0 ; i < n; i ++){
        vector<string> words = splitF(lines2[i]);
        words = sort_words(words);
        lines2[i] = convertVectorToString(words);
    }

}

vector<string> splitF (string s){
    vector<string> words;
    string buffer = "";
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) != ' ' and i + 1 != s.length()) {
            buffer += s.at(i);
        } else {
            if (i + 1 == s.length()) {
                buffer += s.at(i);
            }
            words.push_back(buffer);
            buffer = "";
        }
    }

    return words;

}
vector<string> sort_words(vector <string> words ){
    string buffer;

    string tmp;
    for (int i = 0; i < words.size() ; i ++){
        for ( int j = i + 1; j  < words.size() ; j ++){
            if (tolower(words[i][0]) > tolower(words[j][0]) && words[i] != " " || words[j] == " "){
                tmp = words[i];
                words[i] = words[j];
                words[j] = tmp;
            }
            else if (tolower(words[i][0]) == tolower(words[j][0]) || words[j][0] == ' '){
                for (int k = 1; k  < words[i].size() ; k ++){
                    if (tolower(words[i][k]) > tolower(words[j][k]) || words[j][0] != ' ' && tolower(words[j][k]) < tolower(words[i][0])){
                        break;
                    }
                }
                tmp = words[i];
                words[i] = words[j];
                words[j] = tmp;
            }
        }
    }
    return words;
}
string convertVectorToString(vector<string> words) {
    string s = "";

    for (int i = 0; i < words.size(); i++) {
        if (i + 1 != words.size()) {
            s += words[i] + " ";
        }
        else {
            s += words[i];
        }
    }
    return s;
}
void outFileText(string name){
    ifstream outfile (name);
    string temp;
    cout << outfile.rdbuf()<<"\n";
    outfile.close();
}




