#include <bits/stdc++.h>
using namespace std;
#define ll long long
//brute force
class Solution {
public:
    ll largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll maxi=-1,sum=0,maxSum=-1;
        int i,j,n=nums.size();
        for(i=0;i<n;++i) {
            sum=0;
            for(j=i;j<n;++j) {
                sum+=nums[j];
                if(j-i>=2) {
                    if((sum-nums[j])>nums[j]) {
                        maxSum=max(maxSum,sum);
                    }
                }
            }
            maxi=max(maxi,maxSum);
        }
        return maxi;
    }
};
//most optimal
class Solution {
public:
    ll largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll maxi=-1,sum=0;
        int n=nums.size();
        for(int i=0;i<n;++i) {
           if(i>=2 && sum>=nums[i]) {
                maxi=max(maxi,sum+nums[i]);
           }
           sum+=nums[i];
        }
        return maxi;
    }
};
