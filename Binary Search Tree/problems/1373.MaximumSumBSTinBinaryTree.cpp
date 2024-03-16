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
//modified Size of largest bst in binary tree
class NodeValue {
public:
    int maxNode, minNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum) {
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSum=maxSum;
    }   
}; 

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        //an empty tree is a bst of size 0;
        if(!root)   return NodeValue(INT_MAX,INT_MIN,0);

        //get values from left & right subtree of current tree
        auto left=largestBSTSubtreeHelper(root->left);
        auto right=largestBSTSubtreeHelper(root->right);

        //current node is greater than max in left AND smaller than min in right, it is BST
        if(left.maxNode < root->val && root->val < right.minNode) {
            //it is a bst
            ans=max(ans, root->val+left.maxSum+right.maxSum);
            return NodeValue(min(root->val, left.minNode),max(root->val, right.maxNode), 
                            root->val+left.maxSum+right.maxSum);
    }

        //otherwise, return [-inf,inf] so that parent can't be a valid bst
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSum,right.maxSum));
    }
public:
    int ans; //storing the max sum of all bsts encountered
    int maxSumBST(TreeNode* root) {
        ans=0; //sum>=0 overall sum of a bst cannot be negative as shown in e.g 3
        largestBSTSubtreeHelper(root); 
        return ans;
    }
};