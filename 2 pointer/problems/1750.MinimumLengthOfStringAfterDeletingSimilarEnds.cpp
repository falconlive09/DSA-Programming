#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int low=0,high=n-1;
        if(s[low]!=s[high]) return s.length();

        while(low<high) {
            if(s[low]==s[high]) {
                while(s[low+1]==s[low] && low+1<high) {
                    low++;
                }
                while(s[high-1]==s[high] && high-1>low) {
                    high--;
                }
                low++;
                high--;
            }
            else
                return (high-low+1);
        }
        return (high>low)? 0 : high-low+1; 
    }
};

//refactored code
class Solution {
public:
    int minimumLength(string &s) {
        int n=s.size();
        int low=0,high=n-1;
        if(s[low]!=s[high]) return s.length();
        while(low<high && s[low]==s[high]) {
            char ch=s[low];
            while(s[low]==ch && low<=high)
                low++;
            while(s[high]==ch && high>=low)
                high--;
        }
        return (high-low+1);
    }
};