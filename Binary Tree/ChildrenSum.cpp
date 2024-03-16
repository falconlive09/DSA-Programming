#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node() {
        this->data = 0;
        left = NULL;
    }
    Node(int data) {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

bool check(Node *node){
    if(node==NULL || (node!=NULL && !node->left && !node->right))  return true;
    int total=0;
    if(node->left)  total+=node->left->data;
    if(node->right)  total+=node->right->data;
    return (node->data)==total && check(node->left) && check(node->right);
}
bool isParentSum(Node *root){
    return check(root);
}