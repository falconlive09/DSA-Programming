#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T dat) {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

void f(BinaryTreeNode<int>* node, int level, vector<int> &res){
    if(node==NULL)  return;
    if(level==res.size())   res.push_back(node->data);
    f(node->left, level+1,res);  //f(node->right, level+1,res); for right view
    f(node->right, level+1,res); //f(node->left, level+1,res); for right view
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> res;
    f(root,0,res);
    return res;
}