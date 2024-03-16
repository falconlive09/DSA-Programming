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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder; //T.C.->O(n) S.C.->O(h) h is the height of the tree
        if(root==NULL)  return preOrder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            preOrder.push_back(root->val);
            if(root->right!=NULL)   st.push(root->right);
            if(root->left!=NULL)    st.push(root->left);
        }
        return preOrder;
    }
};