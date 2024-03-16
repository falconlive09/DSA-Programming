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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur=root;
        while(cur!=NULL) {
            if(cur->left==NULL) {
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            else {
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur) {
                    prev=prev->right;
                }
                if(prev->right==NULL) {
                    prev->right=cur; //thread creation
                    cur=cur->left; //traversal continue
                }
                else {
                    prev->right=NULL; //cut the thread
                    inorder.push_back(cur->val);
                    cur=cur->right; //traversal continue
                }
            }
        }
        return inorder;
    }
};

//preorder morrris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur=root;
        while(cur!=NULL) {
            if(cur->left==NULL) {
                preorder.push_back(cur->val);
                cur=cur->right;
            }
            else {
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur) {
                    prev=prev->right;
                }
                if(prev->right==NULL) {
                    prev->right=cur; //thread creation
                    preorder.push_back(cur->val);
                    cur=cur->left; //traversal continue
                }
                else {
                    prev->right=NULL; //cut the thread
                    cur=cur->right; //traversal continue
                }
            }
        }
        return preorder;
    }
};