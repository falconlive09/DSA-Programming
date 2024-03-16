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
    int findLeft(TreeNode* node){
        if(node==nullptr) return 0;
        return 1+max(findLeft(node->left), findLeft(node->right));
    }

    int findRight(TreeNode* node){
        if(node==nullptr) return 0;
        return 1+max(findRight(node->left), findRight(node->right));
    }

    int findMax(TreeNode* node){
        if(node==nullptr) return 0;

        int leftHeight=findLeft(node->left);
        int rightHeight=findRight(node->right);
        int diameter=leftHeight + rightHeight;

        int leftMax=findMax(node->left);
        int rightMax=findMax(node->right);

        return max(diameter, max(leftMax, rightMax));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return findMax(root);
    }
};

//Optimised[O(n)]
int findMax(TreeNode* node,int &maxi){
    if(node==nullptr) return 0;

    int leftHeight=findMax(node->left,maxi);
    int rightHeight=findMax(node->right,maxi);
    maxi=max(maxi,leftHeight+rightHeight);
    return 1+max(leftHeight,rightHeight);
}
int diameterOfBinaryTree(TreeNode* root) {
    int maxi=0;
    findMax(root,maxi);
    //return findMax(root,maxi); returns the max depth(or height of the tree)
    return maxi;
}