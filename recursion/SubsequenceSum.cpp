#include<bits/stdc++.h>
using namespace std;
void printS(int ind,vector<int> &ds,int s,int sum,int arr[],int n)
{
    if(ind==n){
        if(s==sum){
        for(auto it: ds)    
            cout<< it << " ";
        cout<<"\n";
        }
        return;
    }
    //take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    s+=arr[ind];
    printS(ind+1,ds,s,sum,arr,n); 
    s-=arr[ind];
    ds.pop_back();
    //not pick or not take condition, this element is not added to the subsequence  
    printS(ind+1,ds,s,sum,arr,n);
    //can do in the reverse order with not pick first and then pick second
}
int main()
{
    int arr[]={1,1,2};
    int n=3,sum=2;
    vector<int> ds;
    printS(0,ds,0,sum,arr,n);
    return 0;
}