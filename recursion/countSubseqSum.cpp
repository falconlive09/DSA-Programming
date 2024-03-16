#include<bits/stdc++.h>
using namespace std;
int printS(int ind,int s,int sum,int arr[],int n)
{
    //condition not satisfied 
    //can only be done if array contains positives only
    if(s>sum)   return 0;
    if(ind==n){
        //condition satisfied
        if(s==sum)
            return 1;
        //condition not satisfied
        else return 0;
    }
    //take or pick the particular index into the subsequence
    s+=arr[ind];
    
    int l=printS(ind+1,s,sum,arr,n);
    
    s-=arr[ind];
    
    //not pick or not take condition, this element is not added to the subsequence  
    int r=printS(ind+1,s,sum,arr,n);
    //can do in the reverse order with not pick first and then pick second
    return l+r;
}
int main()
{
    int arr[]={1,1,2};
    int n=3,sum=2;
    cout<< printS(0,0,sum,arr,n);
    return 0;
}