#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto &it:arr) {
            mp[it]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &p:mp) {
            pq.push(p.second);
        } 
        while (!pq.empty() && k>0) {
            k-=pq.top();
            if(k>=0)
                pq.pop();   
        }
        return pq.size();
    }
};
//most optimal using bucket sort
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto &it:arr) {
            mp[it]++;
        }
        vector<int> freq(arr.size()+1, 0);
        for(auto &m:mp) {
            freq[m.second]++;
        }
        int res=mp.size(); //length of unique integers
        for(int i=1;i<freq.size();i++) {
            int remove=freq[i];
            if(k>=i*remove) {
                k-=i*remove;
                res-=remove;
            }
            else {
                remove=k/i;
                res-=remove;
                break;
            }
        }
        return res;
    }
};