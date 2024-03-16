#include <bits/stdc++.h>
using namespace std;
//TC-> O(n^2) - Worst, Average Case O(n) - Best Case for sorted array
void insertion_sort(vector<int> &arr,int &n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
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
    insertion_sort(arr,n);
    cout<<"\nAfter Sort \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}