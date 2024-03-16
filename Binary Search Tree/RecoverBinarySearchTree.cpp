#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* first, *prev, *middle, *last;
    void inorder(TreeNode* root) {
        if(root==NULL)  return;
        inorder(root->left);
        if(prev!=NULL && (root->val < prev->val)) {
            //if this is the first violation
            //'first' and 'middle'
            if(first==NULL) {
                first=prev;
                middle=root;
            }
            //if this is the second violation
            else
                last=root;
        }
        //Mark this node as previous
        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)   swap(first->val, last->val);
        else if(first && middle)    swap(first->val, middle->val);
    }
};