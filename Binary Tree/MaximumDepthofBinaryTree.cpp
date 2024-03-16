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

//T.C.-> O(n) S.C.-> O(height of tree)
class Solution {
public: 
    int maxDepthRecur(TreeNode* node,int count){
        if(node==NULL) return 0;
        int left=1+maxDepthRecur(node->left,count+1);
        int right=1+maxDepthRecur(node->right,count+1);
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
       return maxDepthRecur(root,1);  
    }
};

//Using level order traversal
int maxDepth(TreeNode* root) {
    int depth=0;
    if(root==NULL)  return 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        ++depth;
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode *node=q.front();
            q.pop();
            if(node->left!=NULL)    q.push(node->left);
            if(node->right!=NULL)   q.push(node->right);
        }
    }
    return depth;
}