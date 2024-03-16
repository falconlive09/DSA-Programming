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
//using level order traversal
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; 
        queue<pair<TreeNode*, pair<int, int>>> todo; //node,vertical,level
        todo.push({root, {0,0}});
        while (!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* node=p.first;
            int x=p.second.first, y=p.second.second; //vertical & level 
            nodes[x][y].insert(node->val);
            if(node->left)  todo.push({node->left, {x-1, y+1}});
            if(node->right) todo.push({node->right, {x+1, y+1}});
        }
        vector<vector<int>> ans;
        for(auto &p: nodes){
            vector<int> col;
            for(auto &q: p.second)   col.insert(col.end(),q.second.begin(), q.second.end());
            ans.push_back(col);
        }
        // for single vector return
        // vector<int> ans;
        // for(auto &p : nodes){
        //     for(auto &q : p.second){
        //         for(auto &val : q.second){
        //             ans.push_back(val);
        //         }
        //     }
        // }
        return ans;
    }
};