//not working
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool visited[numCourses];
        for(int i = 0; i < prerequisites.size(); i++) {
            visited[prerequisites[i][0]]=false;
        }
        int count = 0;
        stack<int>st;
        for(int i = 0; i < numCourses; i++) {
            if(visited[i]==false)
                DFS(prerequisites,i,st,visited);
        }
        while(st.empty()==false)
        {
            count++;
            st.pop();
        }
        if(count != numCourses)
            return false;
        else
            return true;    
    }
	void DFS(vector<vector<int>>& prerequisites,int s,stack<int>&st,bool *visited)
	{
	    visited[s]=true;
	    for(int u:prerequisites[s])
	    {
	        if(visited[u]==false)
	            DFS(prerequisites,u,st,visited);
	    }
	    st.push(s);
	}
};

int main() {
    Solution s;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    bool result = s.canFinish(numCourses, prerequisites);
    cout << "Result: " << result << endl;
    return 0;
}
