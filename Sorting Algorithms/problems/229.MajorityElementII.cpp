#include <bits/stdc++.h>
using namespace std;

//optimal
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int majorityCount=floor(n/3);
        vector<int> result;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto &it:mp){
            if(it.second>majorityCount)
                result.push_back(it.first);
        }
        return result;
    }
};

//Best Solution
vector<int> majorityElement(vector<int>& nums) {
    int n=nums.size();
    int majorityCount=floor(n/3);
    vector<int> result;
    int count1=0,count2=0;
    int el1,el2;
    //Moore's Voting Algorithm
    for(int i=0;i<n;i++){
        if(count1==0 && el2!=nums[i]){
            count1=1;
            el1=nums[i];
        }
        else if(count2==0 && el1!=nums[i]){
            count2=1;
            el2=nums[i];
        }
        else if(nums[i]==el1)   count1++;
        else if(nums[i]==el2)   count2++;
        else{
            count1--;
            count2--;
        }
    }
    //Checking the majority element
    count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==el1)    count1++;
        if(nums[i]==el2)    count2++;
    }
    if(count1>majorityCount)
        result.push_back(el1);
    if(count2>majorityCount)
        result.push_back(el2);
    return result;
}