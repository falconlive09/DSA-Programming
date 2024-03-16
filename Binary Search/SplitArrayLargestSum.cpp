#include <bits/stdc++.h>
using namespace std;

//same as book allocation & painter partition problem
class Solution {
public:
    int countNoOfStudents(vector<int> &arr,int &pages){
        int student=1,pagesStudent=0;
        for(int i=0;i<arr.size();i++){
            if((pagesStudent+arr[i])<=pages){
                pagesStudent+=arr[i];
            }
            else{
                student++; //go to next student
                pagesStudent=arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int>& arr, int &n, int &m) {
        //m is no of students
        //n is no of books
        if(m>n) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(countNoOfStudents(arr,mid)>m)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
    int splitArray(vector<int>& nums, int &k) {
        int n=nums.size();
        return findPages(nums,n,k);
    }
};