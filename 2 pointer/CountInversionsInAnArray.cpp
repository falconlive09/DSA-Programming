#include <bits/stdc++.h>
using namespace std;

//Merge Sort Code extracted
//int cnt=0; //do not keep global variables in an interview
int merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    int cnt=0;

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
int merge_sort(vector<int> &arr,int low,int high){
    int cnt=0;
    if(low>=high)   return cnt;
    int mid=(low+high)/2;
    cnt+=merge_sort(arr,low,mid);
    cnt+=merge_sort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}

int numberOfInversions(vector<int>&arr, int n) {
    // merge_sort(arr,0,n-1); 
    // return cnt;
    return merge_sort(arr,0,n-1); 
}