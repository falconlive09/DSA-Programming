#include <bits/stdc++.h>
using namespace std;

//Brute Force (Merging to 3rd array)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int n=n1+n2;
        vector<int> nums3;
        int i=0,j=0;
        while(i<n1 && j<n2){ 
            if(nums1[i]<nums2[j])   nums3.push_back(nums1[i++]);
            else    nums3.push_back(nums2[j++]);
        }
        while(i<n1) nums3.push_back(nums1[i++]);
        while(j<n2) nums3.push_back(nums2[j++]);
        if(n%2==1)
            return nums3[n/2];
        return (double)((double)(nums3[n/2])+(double)(nums3[n/2-1]))/2.0;
    }
};

//Most Optimal(binary search) T.C.-> O(log n1) S.C.-> O(1)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size(),n2=nums2.size();
    int left=(n1+n2+1)/2; //no. of elements req on left
    //Perform binary search on smallest
    if(n1>n2)   return  findMedianSortedArrays(nums2,nums1);
    int n=n1+n2;
    int low=0,high=n1;
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=-1e9,l2=-1e9;
        int r1=1e9,r2=1e9;
        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];
        if(mid1-1>=0)  l1=nums1[mid1-1];
        if(mid2-1>=0)  l2=nums2[mid2-1];
        if(l1<=r2 && l2<=r1){
            if(n%2==1) return max(l1,l2);
            return (double)(max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2)  high=mid1-1;
        else if(l2>r1)  low=mid1+1;
    }
    return 0.0;
}