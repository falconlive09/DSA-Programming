#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(char t:tasks)
            freq[t]++;
        priority_queue<int>pq;
        for(auto &c:freq)
            pq.push(c.second);
        int count=0;
        while(!pq.empty())
        {
            int time=0;
            vector<int>temp; 
            for(int i=0;i<n+1;++i)
            {
                if(!pq.empty())
                {
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto t:temp)
            {    
                if(t)
                {
                    pq.push(t);
                }
            }
            count+=pq.empty()? time : n+1;
        }
        return count;
    }
};