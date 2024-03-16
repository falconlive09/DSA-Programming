#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        int i=0,j=0;
        long sum=0,maxi=-1e9;
        while(j<n){
            sum=sum+arr[j];
            if(j-i+1<k)
                j++;
            else if(j-i+1==k){
                maxi=max(maxi,sum);
                sum=sum-arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};