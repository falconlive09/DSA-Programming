#include <bits/stdc++.h>
using namespace std;

//Brute force (TLE)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int majorityCount=floor(n/2);
        cout<<majorityCount;
        int count=0;
        for(int i=0;i<n;i++){
            count=0;
            for(int j=i;j<n;j++){
                if(nums[i]==nums[j])
                    count++;
            }
            if(count>majorityCount)
                return nums[i];
        }
        return -1;
    }
};

//optimal
int majorityElement(vector<int>& nums) {
    int n=nums.size();
    int majorityCount=floor(n/2);
    int count=0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    for(auto &x:mp){
        if(x.second>majorityCount)
            return x.first;
    }
    return -1;
}

//BEST Solution T.C.-> O(n) S.C.-> O(1)

int majorityElement(vector<int>& nums) {
    int n=nums.size();
    int majorityCount=floor(n/2);
    int count=0;
    int el;
    //Moore's Voting Algorithm
    for(int i=0;i<n;i++){
        if(count==0){
            count=1;
            el=nums[i];
        }
        else if(nums[i]==el)
            count++;
        else
            count--;
    }
    //Checking the majority element
    int count1=0;
    for(int i=0;i<n;i++){
        if(nums[i]==el)
            count1++;
    }
    if(count1>majorityCount)
        return el;
    return -1;
}