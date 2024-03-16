#include <bits/stdc++.h>
using namespace std;

//Prerequisite - see median of two sorted array
int kthElement(vector<int> &nums1, vector<int>& nums2, const int &n1,const int &n2, const int &k){
    int left=k; //no. of elements req on left
    //Perform binary search on smallest
    if(n1>n2)   return  kthElement(nums2,nums1,n2,n1,k);
    int n=n1+n2;
    int low=max(0,k-n2),high=min(k,n1); //changed conditions
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=-1e9,l2=-1e9;
        int r1=1e9,r2=1e9;
        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];
        if(mid1-1>=0)  l1=nums1[mid1-1];
        if(mid2-1>=0)  l2=nums2[mid2-1];
        if(l1<=r2 && l2<=r1)    return max(l1,l2);
        else if(l1>r2)  high=mid1-1;
        else if(l2>r1)  low=mid1+1;
    }
    return 0.0;
}