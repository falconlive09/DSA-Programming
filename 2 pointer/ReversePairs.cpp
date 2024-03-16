#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //long long cnt=0; No global for interviews
    void merge(vector<int> &arr,int low,int mid,int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;

        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
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
    }
    long long countPairs(vector<int> &arr,int low,int mid,int high){
        int right=mid+1;
        long long cnt=0;
        for(int i=low;i<=mid;i++){
            while(right<=high && arr[i]>(long long)2*arr[right])
                right++;
            cnt=cnt+(right-(mid+1));
        }
        return cnt;
    }
    long long merge_sort(vector<int> &arr,int low,int high){
        long long cnt=0;
        if(low==high)   return cnt;
        int mid=(low+high)/2;
        cnt+=merge_sort(arr,low,mid);
        cnt+=merge_sort(arr,mid+1,high);
        cnt+=countPairs(arr,low,mid,high);
        merge(arr,low,mid,high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return merge_sort(nums,0,n-1);
    }
};