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
    int maxPath(TreeNode* node,int &maxi){
        if(node==NULL) return 0;

        int leftSum=max(0,maxPath(node->left,maxi)); //max(0,..) so as to eliminate negative max path   
        int rightSum=max(0,maxPath(node->right,maxi));
        maxi=max(maxi,(node->val)+leftSum+rightSum);
        return (node->val)+max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=-1e9;
        maxPath(root,maxi);
        return maxi;
    }
};