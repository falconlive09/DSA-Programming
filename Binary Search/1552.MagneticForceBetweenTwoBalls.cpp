//Similar to Aggressive Cows
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canWePlace(vector<int> &stalls,int &dist,int cows){
        cows=cows-1; //cow placed at 1st stall
        int last=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if((stalls[i]-last)>=dist){
                cows--;
                last=stalls[i];
            }
            if(cows==0)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1,high=position[n-1]-position[0];
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(canWePlace(position,mid,m)==true){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};