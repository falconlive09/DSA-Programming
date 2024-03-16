#include <bits/stdc++.h>
using namespace std;
//T.C.-> O(V+E) S.C.-> O(V)
class Solution {
public: //concept of indegree and outdegree
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outDegree(n+1,0); 
        vector<int> inDegree(n+1,0);
        for(int i=0;i<trust.size();i++) {
            outDegree[trust[i][0]]++;
        }
        for(int i=0;i<trust.size();i++) {
            inDegree[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++) {
            if(outDegree[i]==0 && inDegree[i]==n-1) return i;
        }
        return -1;
    }
};
//improved
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> Degree(n+1,0);
        for(int i=0;i<trust.size();i++) {
            Degree[trust[i][0]]--;
            Degree[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++) {
            if(Degree[i]==n-1) return i;
        }
        return -1;
    }
};