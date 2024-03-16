#include <bits/stdc++.h>
using namespace std;

//better approach
int getLongestSubarray(vector<int> &a, int k){
    unordered_map<int,int> preSumMap;
    int sum=0;
    int maxLen=0;
    for(int i=0;i<a.size();++i) {
        sum+=a[i];
        if(sum==k) {
            maxLen=max(maxLen,i+1);
        }   
        int rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()) {
            int len=i-preSumMap[rem];
            maxLen=max(maxLen,len);
        }
        //condn. will work for postives and negatives
        if(preSumMap.find(sum)==preSumMap.end())
            preSumMap[sum]=i;
        //preSumMap[sum]=i; //only positives
    }
    return maxLen;
}

//optimised for positives only
//sliding window approach
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