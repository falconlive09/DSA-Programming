#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &nums){
    int n=nums.size();
    int low=0,high=n-1;
    int mini=1e9;
    int ind=-1;
    while(low<=high){
        int mid=(low+high)/2;
        //if entire array is sorted (Optimisation)
        if(nums[low]<nums[high]){
            if(nums[low]<mini){
                mini=nums[low];
                ind=low;
            }
            break;
        }
        //left sorted 
        if(nums[low]<=nums[mid]){
            if(nums[low]<mini){
                mini=nums[low];
                ind=low;
            }
            low=mid+1;
        }   
        //right sorted
        else{
            if(nums[mid]<mini){
                mini=nums[mid];
                ind=mid;
            }
            high=mid-1;
        }
    }
    return ind;    
}