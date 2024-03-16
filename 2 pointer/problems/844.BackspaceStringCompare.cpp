#include <bits/stdc++.h>
using namespace std;

//Brute Force O(n) space->O(n)
class Solution {
public:
    bool backspaceCompare(string &s, string &t) {
        stack<char> st1,st2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#' && !st1.empty())
                st1.pop();
            else if(s[i]!='#')
                st1.push(s[i]);
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#' && !st2.empty())
                st2.pop();
            else if(t[i]!='#')
                st2.push(t[i]);
        }
        return st1==st2;
    }
};

//Optimal 2 pointer
bool backspaceCompare(string &s, string &t) {
    int i=s.size()-1,j=t.size()-1;
    while(i>=0 || j>=0){
        int backspaces=0;
        //backspaces>0 e.g.-> if we reach at 1st '#' in #ab##
        while(i>=0 && (backspaces>0 || s[i]=='#')){
            if(s[i]=='#')
                backspaces++;
            else 
                backspaces--;
            i--;
        }
        backspaces=0;
        while(j>=0 && (backspaces>0 || t[j]=='#')){
            if(t[j]=='#')
                backspaces++;
            else 
                backspaces--;
            j--;
        }
        if(i>=0 && j>=0){
            if(s[i]!=t[j])
                return false;
            else{
                i--;
                j--;
            }
        }
        else{
            if(i>=0 || j>=0)
                return false;
        }
    }
    return true;
}