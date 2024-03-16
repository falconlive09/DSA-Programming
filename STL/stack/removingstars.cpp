#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    string removeStars(string s) {
        stack<char> st;
        for (char ch : s) 
        {
            switch(ch)
            {
                case '*':   if(!st.empty())
                                st.pop();
                            break;
                default:    st.push(ch);
            }
        }
        s="";
        while(!st.empty()) 
        {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};    
