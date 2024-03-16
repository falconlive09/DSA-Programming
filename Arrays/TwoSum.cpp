#include<bits/stdc++.h>
using namespace std;
//T.C.->O(n log n) S.C.->O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>indices;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++) {
            if(m.find(target-nums[i])!=m.end()) {
                indices.push_back(i);
                indices.push_back(m[target-nums[i]]);
                return indices;
            }
            else
                m.insert({nums[i],i});
        }
        return indices; 
    }
};
//using 2 pointer T.C.->O(n log n) S.C.->O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
    }
};

int main() {
    vector<int>nums {3,3};       
    vector<int>indices;
    int target=6;
    unordered_map<int,int>m;
    //2 pass hashing
    for(int i=0;i<nums.size();i++){
        m.insert({nums[i],i});
    }
    for(int i=0;i<nums.size();i++){
        if(m.find(target-nums[i])!=m.end() && (m.find(target-nums[i]))->second!=i){
            indices.push_back(i);
            indices.push_back(m[target-nums[i]]);
            break;
        }
    }  
    for(auto x:indices){
        cout<<x<<" ";
    }
    return 0;
}