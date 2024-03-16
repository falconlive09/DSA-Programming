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

class NodeValue {
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;
    }
}; 
class Solution {
public:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        //an empty tree is a bst of size 0;
        if(!root)   return NodeValue(INT_MAX,INT_MIN,0);

        //get values from left & right subtree of current tree
        auto left=largestBSTSubtreeHelper(root->left);
        auto right=largestBSTSubtreeHelper(root->right);

        //current node is greater than max in left AND smaller than min in right, it is BST
        if(left.maxNode < root->data && root->data < right.minNode) {
            //it is a bst
            return NodeValue(min(root->data, left.minNode),max(root->data, right.maxNode),
                            left.maxSize + right.maxSize + 1);
        }

        //otherwise, return [-inf,inf] so that parent can't be a valid bst
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
};
int largestBST(TreeNode * root) {
    Solution s;
    return s.largestBSTSubtreeHelper(root).maxSize;   
}