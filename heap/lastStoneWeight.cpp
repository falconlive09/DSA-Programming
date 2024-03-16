#include<bits/stdc++.h>

using namespace std;
//LC Find K Pairs with Smallest Sums
//revisit this 
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq{stones.begin(),stones.end()};
        int y=0,x=0; //y is the heaviest(pq.top())
        while(pq.size()>1)
        {
            y=pq.top();
            pq.pop();
            x=pq.top();
            pq.pop();
            if(x!=y)
            {   
                pq.push(y-x);
            }
        }
        if(pq.empty())
            return 0;
        else //even if priority queue is empty, pq.top() returns an unidentified value rather than 0 or null value
            return pq.top(); 
    }
};
int main()
{
    Solution S;
    vector<int>t{2,2};
    int n=S.lastStoneWeight(t);
    cout<<n;



    return 0;
}