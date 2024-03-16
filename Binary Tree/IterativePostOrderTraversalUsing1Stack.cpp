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
//1 stack technique T.C.->O(2N) S.C.->O(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root){
    vector<int> postOrder;
    if (root==NULL) return postOrder;
    TreeNode* node=root;
    stack<TreeNode*> st;
    while(node!=NULL || !st.empty()) {
        if(node!=NULL){
        st.push(node);
        node=node->left;
        } 
        else{
        TreeNode *temp=st.top()->right;
        if(temp==NULL){
            temp=st.top();
            st.pop();
            postOrder.push_back(temp->val);
            while(!st.empty() && temp==st.top()->right) {
                temp=st.top();
                st.pop();
                postOrder.push_back(temp->val);
            }
        } else node=temp;
        }
    }
    return postOrder;
    }
};