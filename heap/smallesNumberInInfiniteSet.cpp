#include<bits/stdc++.h>

using namespace std;
class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        for(int i=1;i<=1000;i++)
        {
            pq.push(i);
            s.insert(i);
        }
    }
    
    int popSmallest() 
    {
        int result=pq.top();
        pq.pop();
        s.erase(result);
        return result;
    }
    
    void addBack(int num) 
    {
        if(s.find(num)==s.end())
        {
            pq.push(num);    
            s.insert(num);
        } 
    }
    private:
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_set<int>s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */