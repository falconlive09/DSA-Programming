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
//2 stack technique
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if(root==NULL)  return postOrder;
        stack<TreeNode*> st1,st2; //T.C.->O(N) S.C.->O(2N)
        TreeNode* node=root;
        st1.push(node);
        while(!st1.empty()){
            node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left!=NULL)    st1.push(node->left);
            if(node->right!=NULL)   st1.push(node->right);
        }
        while(!st2.empty()){
            postOrder.push_back(st2.top()->val);
            st2.pop();
        }
        return postOrder;
    }
};