#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> printFirstNegativeInteger(ll int arr[],ll int n, ll int k) {
    vector<ll> ans;
    list<int> l;  
    int i=0,j=0;
    while(j<n){
        if(arr[j]<0)
            l.push_back(arr[j]);
        if(j-i+1<k)
            j++;
        else if(j-i+1==k){
            if(l.size()==0)
                ans.push_back(0);
            else{
                ans.push_back(l.front());
                if(arr[i]==l.front()){
                    l.pop_front(); //FIFO
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}