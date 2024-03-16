#include <bits/stdc++.h>
using namespace std;
//brute force recursive approach -> generate all permutations
//linear search -> ret. next index if not ret. 1st (circular)

//optimal 2 pointer 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1,n=nums.size();
        for(int i=n-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                ind=i;
                break;
            }
        }
        //next of largest permutation(e.g. 54321) will be the smallest permutation(e.g. 12345)
        if(ind==-1) {
            reverse(nums.begin(),nums.end()); 
            return;
        }
        for(int i=n-1;i>=ind;i--) {
            if(nums[i]>nums[ind]) {
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};

//using stl
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};