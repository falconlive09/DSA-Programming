#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    stack<TreeNode*> st;
    //reverse->true -> before
    //reverse->false -> next
    bool reverse=true;
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse=isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode=st.top();
        st.pop();
        if(!reverse) pushAll(tmpNode->right);
        else    pushAll(tmpNode->left);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(TreeNode* node) {
        for(;node!=NULL;) {
            st.push(node);
            if(reverse==true)   node=node->right;
            else    node=node->left; 
        }    
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int &k) {
        if(!root)   return false;
        BSTIterator l(root,false); //next
        BSTIterator r(root,true); //before
        int i=l.next();
        int j=r.next();
        while(i<j) {
            if(i+j==k) return true;
            else if(i+j<k)  i=l.next();
            else    j=r.next();
        }
        return false;
    }
};