#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        //Calculation of First Position
        int low=0,high=n-1;
        int firstPos=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(target==nums[mid]){
                firstPos=mid;
                high=mid-1;
            }
            else if(target>nums[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        if(firstPos==-1)
            return {-1,-1};
        //Calculation for Last Position
        low=0,high=n-1;
        int lastPos=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(target==nums[mid]){
                lastPos=mid;
                low=mid+1;
            }
            else if(target>nums[mid])   
                low=mid+1;
            else    
                high=mid-1;
        }
        //No. of occurences of the same number 
        //(lastPos-firstPos)+1;
        return {firstPos,lastPos};
    }
};