#include <iostream>
#define COUNT 10
using namespace std;
struct Node{
    double data ;
    Node * left;
    Node * right;

};
class Tree {
    Node * root ;
    void addElementRec(Node *& node , double value);//add element in tree rec
    void printBT(Node *root, int space);//print rec tree
    double getMax(Node * node);

public:
    Tree();
    void addEle(double value);
    void printTree();
    double getmax();
    //void printMax();
};