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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        int ans=0;
        queue<pair<TreeNode*, int>>q; //int is the index
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int mmin=q.front().second; //to make the index starting from 0
            int first,last;
            for(int i=0;i<size;i++){
                int cur_id=q.front().second-mmin;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)    first=cur_id; //storing the first node
                if(i==size-1)   last=cur_id;
                if(node->left)  q.push({node->left, (long long)cur_id*2+1});
                if(node->right) q.push({node->right, (long long)cur_id*2+2});
            }
            ans=max(ans, last-first+1);
        }
        return ans;
    }
};