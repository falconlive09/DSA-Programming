#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};


pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    pair<int,int> p{-1,-1};
    TreeNode* temp=root;
    while(root!=NULL) {
        if(key>=root->data) {
            root=root->right;
        }
        else {
            p.second=root->data;
            root=root->left;
        }
    }
    while(temp!=NULL) {
        if(key<=temp->data) {
            temp=temp->left;
        }
        else {
            p.first=temp->data;
            temp=temp->right;
        }
    }
    return p;
}