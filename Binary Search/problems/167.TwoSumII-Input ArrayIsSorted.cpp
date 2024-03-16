#include <bits/stdc++.h>
using namespace std;

//brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int>ans(2);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(numbers[i]+numbers[j]==target){
                    ans[0]=i+1;
                    ans[1]=j+1;
                    return ans;
                }
            }
        }
        return {-1,-1};
    }
};

//most optimised
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0,r=n-1;
        while(l<r){
            int val=numbers[l]+numbers[r];
            if(val==target) return {l+1,r+1};
            else if(val>target) --r;
            else    ++l;
        }        
        return {};
    }
};