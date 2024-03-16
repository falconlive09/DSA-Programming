#include <bits/stdc++.h>
using namespace std;
//For positive numbers only 
//Try for negative numbers too (hint: Use hashmap)
int longestSubarrayWithSumK(vector<int> &arr, long long k) {
    int n=arr.size();
    long long sum=0;
    int maxi=-1e9;
    int i=0,j=0;
    while(j<n){
        sum=sum+arr[j];
        if(sum<k)
            j++;
        else if(sum==k){
            maxi=max(maxi,(j-i+1));
            j++;
        } 
        else if(sum>k){
            while(sum>k){
                sum=sum-arr[i];
                i++;
                if(sum==k){
                    maxi=max(maxi,(j-i+1));
                }
            }
            j++;
        }
    }
    return maxi;
}