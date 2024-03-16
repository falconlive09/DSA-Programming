#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n){
    if(n==0 || n==1)    return n;
    int low=1,high=n;
    long long ans=0;
    while(low<=high){
        long long mid=(low+high)/2;
        if((mid*mid)<=n){
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return ans;
}