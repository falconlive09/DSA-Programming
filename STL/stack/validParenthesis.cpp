#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s)
        {
            if(ch=='(' || ch=='{' || ch=='[')
                st.push(ch);
            else
            {
                if(st.empty())
                    return false;
                switch(st.top())
                {
                    case '(':   if(ch==')') 
                                    st.pop();
                                else
                                    return false;
                                break;
                    case '{':   if(ch=='}') 
                                    st.pop();
                                else
                                    return false;
                                break;
                    case '[':   if(ch==']') 
                                    st.pop();
                                else
                                    return false;
                                break;
                }           
            }
        }
        return st.empty(); 
    }
};