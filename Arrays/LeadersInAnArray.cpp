#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int>&a) {
    vector<int> ans;
    int maxi=-1e9,n=a.size();
    for(int i=n-1;i>=0;i--) {
        if(a[i]>maxi) {
            ans.push_back(a[i]);
            maxi=a[i];
        }
    }
    return ans;
}