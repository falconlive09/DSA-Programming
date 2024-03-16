#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=-1,n=nums.size();
        if(n==1) return;
        for(int i=0;i<n;++i) {
            if(nums[i]==0) {
                j=i;
                break;
            }
        }
        if(j==-1) return;
        for(int i=j+1;i<n;++i) {
            if(nums[i]!=0) {
                swap(nums[j],nums[i]);
                j++;
            }
        }
    }
};