#include <bits/stdc++.h>
using namespace std;
//Brute Force TLE O(n^3 log(no. of unique triplets)) Space-> O(2*no of triplets)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> s; //storing distinct elements
        //why not unordered_set? 
        //coz unordered_set does not have hashing fxn for data type vector<int>
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};

//hashing gives TLE O(n^2*log m)
vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        unordered_set<int> hashSet;
        for(int j=i+1;j<n;j++){
            int third=-(nums[i]+nums[j]);
            if(hashSet.find(third)!=hashSet.end()){
                vector<int> temp={nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                s.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(s.begin(),s.end());
    return ans;
}

//2 pointer optimal O(nlogn + O(nxn))
vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])
            continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{ //equal one of the triplet
                vector<int> temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
    return ans;
}