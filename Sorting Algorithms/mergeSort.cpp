#include <bits/stdc++.h>
using namespace std;
//TC-> O(nlog n)- Best, Worst & Average
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
void merge_sort(vector<int> &arr,int low,int high){
    if(low==high)   return;
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void mergeSort(vector<int> &arr, int n) {
    merge_sort(arr,0,n-1);
}

int main(){
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    cout<<"Enter elements of the array\n";
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Before Sort \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    mergeSort(arr,n);
    cout<<"\nAfter Sort \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}