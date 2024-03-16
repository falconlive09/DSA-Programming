#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long fun(vector<int> &piles,int hourly,int &n){
        long long totalhrs=0;
        for(int i=0;i<n;i++){
            totalhrs+=ceil((double)piles[i]/(double)hourly);
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        long long totalHrs;
        while(low<=high){
            int mid=(low+high)/2;
            totalHrs=fun(piles,mid,n);
            if(totalHrs<=h){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans; 
    }
};