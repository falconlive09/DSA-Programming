#include <bits/stdc++.h>
using namespace std;

int lowerBound(int *arr, int &n, int &x) {
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=arr[mid];
            high=mid-1;
        }
        else    
            low=mid+1;
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int *arr, int n, int &x) {
	sort(arr,arr+n);
	pair<int,int> answer;
    int low=0,high=n-1;
    int floor=-1;
    while(low<=high){ 
        int mid=(low+high)/2;
        if(arr[mid]<=x){
            floor=arr[mid];
            low=mid+1;
        }
        else    
            high=mid-1;
    }
    answer.first=floor;
    answer.second=lowerBound(arr,n,x);
    return answer;
}