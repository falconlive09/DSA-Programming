#include <bits/stdc++.h>
using namespace std;
//TC-> O(n^2) Best, Worst & Average Case
void selection_sort(vector<int> &arr,int &n){
    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        swap(arr[mini],arr[i]);
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
    selection_sort(arr,n);
    cout<<"\nAfter Sort \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}