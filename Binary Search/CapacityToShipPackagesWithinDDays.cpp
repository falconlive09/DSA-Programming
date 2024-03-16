#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int daysRequired(vector<int>& weights, int &capacity,int &n){
        int days=1,load=0;
        for(int i=0;i<n;i++){
            if(load+weights[i]>capacity){
                days=days+1;
                load=weights[i];
            }
            else
                load+=weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end()),
        high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(daysRequired(weights,mid,n)<=days)
                high=mid-1;
            else
                low=mid+1;
        } 
        return low;
    }
};