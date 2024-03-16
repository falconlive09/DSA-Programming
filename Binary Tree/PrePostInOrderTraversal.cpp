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

//Recursive Solution
class Solution {
public:
    void preorder(TreeNode* node,vector<int>&arr){
        if(node==NULL)
            return;
        arr.push_back(node->val); //PreOrder
        preorder(node->left,arr);
        //arr.push_back(node->val); Inorder
        preorder(node->right,arr);
        //arr.push_back(node->val); PostOrder
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
};