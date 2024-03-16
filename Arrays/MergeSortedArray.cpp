#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>&a, const int &n, vector<int>&b, const int &m) {
        vector<int> uni;
        int i=0,j=0;
        while(i<n && j<m) {
            if(a[i]<=b[j]) {
                uni.push_back(a[i]);
                ++i;
            }
            else {
                uni.push_back(b[j]);
                ++j;
            }
        }
        while(i<n) {
            uni.push_back(a[i]);
            ++i;
        }
        while(j<m) {
            uni.push_back(b[j]);
            ++j;
        }
        a=uni;
    }
};