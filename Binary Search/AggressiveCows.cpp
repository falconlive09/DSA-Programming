#include <bits/stdc++.h>
using namespace std;

//BruteForce O(n^2)
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
int aggressiveCows(vector<int> &stalls, int &cows){
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int limit=stalls[n-1]-stalls[0];
    for(int i=1;i<=limit;i++){
        if(canWePlace(stalls,i,cows)==true)
            continue;
        else
            return i-1;
    }
    return limit;
}

//Optimal
int aggressiveCows(vector<int> &stalls, int &cows){
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1,high=stalls[n-1]-stalls[0];
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(canWePlace(stalls,mid,cows)==true){
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return ans;
} 