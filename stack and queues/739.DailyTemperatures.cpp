#include <bits/stdc++.h>
using namespace std;

//like next greater element
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> nge(n,0);
        stack<pair<int,int>> st; //keep track of next greater and its index
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && st.top().first <= temperatures[i%n]) {
                st.pop();
            }
            if(i<n) {
                if(!st.empty()) nge[i]=st.top().second - i;
            }
            st.push({temperatures[i%n],i});
        }
        return nge;
    }
};