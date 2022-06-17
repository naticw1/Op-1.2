#include <iostream>
#include "foo.h"
int main (){
    Tree tree;
    int size = inputNumber();
    addElemnts(tree, size);
    cout << "Tree: "<<endl;
    tree.printTree();
    double max;
    cout <<"Max Element :"<<endl;
    max = tree.getmax();
    cout <<max;
    //tree.printMax();
}

