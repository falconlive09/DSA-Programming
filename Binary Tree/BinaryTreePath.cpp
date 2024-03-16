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
    void getPath(TreeNode* root, string s,vector<string> &ans){
        if(!root)   return;

        if(root->left==NULL && root->right==NULL){
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(root->val)+"->";
        if(root->left)
            getPath(root->left,s,ans);
        if(root->right)
            getPath(root->right,s,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL) return ans;
        getPath(root,"",ans);
        return ans;
    }
};