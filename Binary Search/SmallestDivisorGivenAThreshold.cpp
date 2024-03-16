#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfDivisor(vector<int> &nums,int &div,int &n){ 
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=ceil((double)(nums[i])/(double)(div));
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int &threshold) {
        int n=nums.size();
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(sumOfDivisor(nums,mid,n)<=threshold)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};