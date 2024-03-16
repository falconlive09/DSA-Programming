#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Kadane's Algorithm T.C.-> O(N) S.C.-> O(1)
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN,sum=0;
        int start=0,ansStart=-1,ansEnd=-1; //printing the max subarray sum
        for(int i=0;i<n;i++) {
            if(sum==0)  start=i;
            sum+=nums[i];
            if(sum>maxi) {
                maxi=sum;
                ansStart=start;
                ansEnd=i;
            }
            if(sum<0)   sum=0;
        }
        return maxi;
    }
};