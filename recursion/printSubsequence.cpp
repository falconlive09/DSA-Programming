#include<bits/stdc++.h>
using namespace std;
void printF(int ind,vector<int> &ds,int arr[],int n)
{
    //Time Complexity -> n * 2^n
    //Space Complexity -> O(n) 
    if(ind==n){
        for(auto it: ds) //O(n) generally
            cout<< it << " ";
        if(ds.size()==0) //for the null array to be printed
            cout<<"{}";
        cout<<"\n";
        return;
    }
    //take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    printF(ind+1,ds,arr,n); 
    ds.pop_back();
    //not pick or not take condition, this element is not added to the subsequence  
    printF(ind+1,ds,arr,n);
    //can do in the reverse order with not pick first and then pick second
}
int main()
{
    int arr[]={3,1,2};
    int n=3;
    vector<int> ds;
    printF(0,ds,arr,n);
    return 0;
}