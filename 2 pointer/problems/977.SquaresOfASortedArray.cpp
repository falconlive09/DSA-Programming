#include <bits/stdc++.h>
using namespace std;
//brute force
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};

//optimised & refactored T.C.-> O(n) S.C.->O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int low=0,high=n-1;
        int pos=n-1;
        while(low<=high) {
            if(abs(nums[low])<abs(nums[high])) {
                ans[pos--]=nums[high]*nums[high];
                high--;
            }
            else {
                ans[pos--]=nums[low]*nums[low];
                low++;
            }
        }
        return ans;
    }
};

//easy understand logic
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int low=0,high=n-1;
        while(low<=high) {
            if(abs(nums[low])<abs(nums[high])) {
                ans.insert(ans.begin(),nums[high]*nums[high]);
                high--;
            }
            else if(abs(nums[low])>abs(nums[high])) {
                ans.insert(ans.begin(),nums[low]*nums[low]);
                low++;
            }
            else {
                if(low!=high) {
                    ans.insert(ans.begin(),nums[low]*nums[low]);
                    ans.insert(ans.begin(),nums[high]*nums[high]);
                    low++;
                    high--;
                }
                else {
                    ans.insert(ans.begin(),nums[low]*nums[low]);
                    low++;
                }
            }
        }
        return ans;
    }
};