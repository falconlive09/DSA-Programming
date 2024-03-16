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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)  return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=true; //true means left to right and vice-versa

        while(!q.empty()){
            int size=q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();

                //find position to fill node's value
                int index=(leftToRight)? i:(size-1-i);
                row[index]=node->val;
                if(node->left!=NULL)    q.push(node->left);
                if(node->right!=NULL)   q.push(node->right);
            }
            leftToRight=!leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};