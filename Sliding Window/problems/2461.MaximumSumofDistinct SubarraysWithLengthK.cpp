#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
        int i=0,j=0;
        long long sum=0,maxi=0;
        while(j<n){
            mp[arr[j]]++;
            sum=sum+arr[j];
            if(j-i+1<k)
                j++;
            else if(j-i+1==k){
                if(mp.size()==k) //three distinct elements in a map
                    maxi=max(maxi,sum);
                sum=sum-arr[i];
                mp[arr[i]]--;
                if(mp[arr[i]]<1) //count of element <1 in a map, then erase it
                    mp.erase(arr[i]); 
                i++;
                j++;
            }
        }
        return maxi;
    }
};