#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int mini=1e9;
        while(low<=high){
            int mid=(low+high)/2;
            //if entire array is sorted (Optimisation)
            if(nums[low]<=nums[high]){
                mini=min(mini,nums[low]);
                break;
            }
            //left sorted 
            if(nums[low]<=nums[mid]){
                mini=min(mini,nums[low]);
                low=mid+1;
            }   
            //right sorted
            else{
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
        }
        return mini;
    }
};