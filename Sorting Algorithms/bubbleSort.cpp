#include <bits/stdc++.h>
using namespace std;
//TC-> O(n^2) - Worst Case,Average Case O(n)- Best Case
void bubble_sort(vector<int> &arr,int &n){
    for(int i=n-1;i>=1;i--){
        int didSwap=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap=1;
            }
        } 
        if(didSwap==0) //if array is sorted break out of loop
            break;
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
    bubble_sort(arr,n);
    cout<<"\nAfter Sort \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}