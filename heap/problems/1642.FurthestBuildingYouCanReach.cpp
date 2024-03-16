#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxDiff; //max heap to store diff in height
        int n=heights.size();
        for(int i=0;i<n-1;i++) {
            if(heights[i+1] <= heights[i])  continue;
            else {
                int diff=heights[i+1]-heights[i];
                maxDiff.push(diff);
                bricks-=diff;
                if(bricks<0) {
                    if(ladders==0) return i;
                    --ladders;
                    bricks+=maxDiff.top();
                    maxDiff.pop(); 
                }
            }
        }
        return n-1;
    }
};