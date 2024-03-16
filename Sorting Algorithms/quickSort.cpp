#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i<=high-1)  i++; //arr[i]>pivot for descending 
        while(arr[j]>arr[pivot] && j>=low+1)    j--; //arr[j]<=pivot for descending
        if(i<j) swap(arr[i],arr[j]);
    }
    //Time for pivot to come to right place
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int> &arr,int low,int high){
    if(low<high){
        int partitionIndex=f(arr,low,high);
        qs(arr,low,partitionIndex-1);
        qs(arr,partitionIndex+1,high);
    }
}
vector<int> quickSort(vector<int> &arr)
{
    qs(arr,0,arr.size()-1);
    return arr;
}

int main(){
    vector<int> arr={5,4,3,2,1};
    quickSort(arr);
    for(auto i:arr) cout<<i<<" ";
    return 0;
}