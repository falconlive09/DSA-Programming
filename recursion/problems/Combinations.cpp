#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int ind,int &n,int &k,vector<vector<int>> &ans,vector<int> &ds){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<=n;i++){
            ds.push_back(i);
            f(i+1,n,k,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(1,n,k,ans,ds);
        return ans;
    }
};  

int main(){
   return 0;
}