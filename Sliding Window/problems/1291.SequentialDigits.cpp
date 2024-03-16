#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string number="123456789";
        vector<int> ans;
        int lowLimit=to_string(low).length();
        int highLimit=to_string(high).length();
        for(int len=lowLimit; len<=highLimit; len++) {
            for(int i=0;i<=9-len;i++) {
                string sq=number.substr(i,len);
                int num=stoi(sq);
                if(num>=low && num<=high)    ans.push_back(num);
            }
        }
        return ans;
    }
};