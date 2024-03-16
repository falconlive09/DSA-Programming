#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(0);
    } 
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto i:arr)
            mp[i]++;
        priority_queue<pair<int,int>>pq;
        for(auto f:mp)
            pq.push({f.second,f.first});
        int sum = 0, count = 0;
        while(!pq.empty()) {
            sum += pq.top().first;
            count++;
            pq.pop();
            if(sum >= arr.size() / 2) break;
        }
        return count;
    }   
};
int main()
{
    Solution S;
    vector<int>t{3,3,3,3,5,5,5,5,2,2,7};
    int n=S.minSetSize(t);
    cout<<n;



    return 0;
}