#include <bits/stdc++.h>
using namespace std;
//next smaller element concept
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> nge=prices;
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && st.top() > prices[i%n]) {
                st.pop();
            }
            if(i<n) {
                if(!st.empty()) nge[i]-=st.top();
            }
            st.push(prices[i%n]);
        }
        return nge;
    }
};