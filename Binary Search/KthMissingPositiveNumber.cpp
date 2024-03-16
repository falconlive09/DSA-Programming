#include <bits/stdc++.h>
using namespace std;

//BruteForce T.C.->O(n) S.C.->O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int &k) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=k)    k++;
            else    break;
        }
        return k;
    }
};

//Optimal Solution
class Solution {
public:
    int findKthPositive(vector<int>& arr, int &k) {
        int n=arr.size();
        int low=0,high=n-1,missing;
        while(low<=high){
            int mid=(low+high)/2;
            missing=arr[mid]-(mid+1);
            if(missing<k)   low=mid+1;
            else    high=mid-1;
        }
        return high+1+k; //or (low+k)
    }
};