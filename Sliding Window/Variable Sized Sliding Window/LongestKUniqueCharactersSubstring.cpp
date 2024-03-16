#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string &s, int &k) {
        int n=s.size();
        unordered_map<char,int> mp;
        int i=0,j=0;
        int maxi=-1;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()<k)
                j++;
            else if(mp.size()==k){
                maxi=max(maxi,(j-i+1));
                j++;
            } 
            else if(mp.size()>k){
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) //count of character gets 0 delete it from map
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
    return 0;
}