#include <iostream>
#include "foo.h"
int main () {
    vector<TVector *> arr;
    vector<TVector *> paral;
    vector<TVector *> perpen;
    create_arr(arr , 3, 4);
    out_All(arr ,3 ,4);
    cout << "sum of parallel vectors to 0-vec :"<<sum_of_Paralel(arr, 3 , paral)<<endl;
    cout << "sum of perpendicular vectors to 0-vec:"<<sum_of_Perpen(arr ,3,4 ,perpen)<<endl;
    out_to_zero(paral ,"All vectors that paral. to 0-vec :");
    out_to_zero(perpen , "All vectors that perpen. to 0-vec :");
}