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
    TreeNode* markParent(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*> &parent_track, int &start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node=q.front();
            if(node->val==start)    res=node;
            q.pop();
            if(node->left) {
                parent_track[node->left]=node;
                q.push(node->left);
            }
            if(node->right) {
                parent_track[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int &start) {   
        unordered_map<TreeNode*, TreeNode*> parent_track; //storing node->parent
        TreeNode* target=markParent(root,target,parent_track,start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int time=0;
        while(!q.empty()) {
            int size=q.size();
            int flag=0;
            for(int i=0;i<size;i++) {
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited[current->left]) {
                    flag=1;
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]) {
                    flag=1;
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    flag=1;
                    q.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }
            if(flag)    time++;
        }
        return time;
    }
};