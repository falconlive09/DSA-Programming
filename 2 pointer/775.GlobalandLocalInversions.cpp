#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Merge Sort Code extracted
    //int cnt=0; //do not keep global variables in an interview
    vector<int> temp; //to avoid TLE
    long long merge(vector<int> &arr,int low,int mid,int high){
        temp.clear();
        int left=low;
        int right=mid+1;
        long long cnt=0;

        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{ //right is smaller
                cnt+=(mid-left+1); //addition of pairs where a[left]>a[right]
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        //Changing the original array with the temp
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        return cnt;
    }
    long long merge_sort(vector<int> &arr,int low,int high){
        long long cnt=0;
        if(low>=high)   return cnt;
        int mid=(low+high)/2;
        cnt+=merge_sort(arr,low,mid);
        cnt+=merge_sort(arr,mid+1,high);
        cnt+=merge(arr,low,mid,high);
        return cnt;
    }
    bool isIdealPermutation(vector<int>& nums) {
        // merge_sort(arr,0,n-1); 
        // return cnt;
        int n=nums.size();
        long long localInver=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                localInver++;
            }
        }
        long long globalInver=merge_sort(nums,0,n-1);
        return globalInver==localInver;
    }
};

//Alternate Approach
bool isIdealPermutation(vector<int> &nums) {
    int cmax=0, n=nums.size();
    for (int i=0;i<n-2;++i) {
        cmax=max(cmax,nums[i]);
        if (cmax>nums[i + 2]) return false;
    }
    return true;
}