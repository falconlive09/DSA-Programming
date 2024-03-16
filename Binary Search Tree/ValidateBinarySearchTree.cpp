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
public:
    bool isValid(TreeNode* root, long minVal, long maxVal) {
        if(root==NULL)  return true;
        if(root->val>=maxVal || root->val<=minVal)  return false;
        return isValid(root->left,minVal,root->val) 
            && isValid(root->right,root->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,INT_MIN,INT_MAX);
    }
};