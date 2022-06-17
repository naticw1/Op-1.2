#include "Tree.h"
Tree::Tree() {
    root = nullptr;
}
void Tree::addElementRec(Node *& node, double value) {//add elemnts rec
    if (!node) {//
        node = new Node;
        node->left = nullptr;
        node->right = nullptr;
        node->data = value;
        return;
    }

    if (value >= node->data) {
        addElementRec(node->right, value);
    }
    else {
        addElementRec(node->left, value);
    }
}
void Tree::addEle(double value) {
    this->addElementRec(root , value);
}
void Tree::printBT(Node *root, int space)
{

    if (root == nullptr)// base case
        return;

    space += COUNT;// + distance level

    printBT(root->right, space);//print right

    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";


    printBT(root->left, space);// print left
}
void Tree::printTree() {
    this->printBT(root , 0);//initializer and print
}

double Tree::getMax(Node* node) {
    if (node->right != nullptr) {
        return getMax(node->right);
    }
    else {
        return node->data;
    }
}
double Tree::getmax() {
    this->getMax(root);
}
/*void Tree::printMax() {
    cout <<getMax(root);

}*/
