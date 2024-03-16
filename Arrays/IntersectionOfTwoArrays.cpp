#include <bits/stdc++.h>
using namespace std;
//repitition or duplicates allowed
vector<int> findArrayIntersection(vector<int> &a, int n, vector<int> &b, int m) {
	vector<int> ans;
	int i=0,j=0;
	while(i<n && j<m) {
		if(a[i]<b[j])    i++;
		else if(b[j]<a[i])  j++;
		else { 
			//both elements are equal
			ans.push_back(a[i]); 
			i++;
			j++;
		}
	}
	return ans;
}

//only unique
class Solution {
public:
    vector<int> intersection(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        int n=a.size(),m=b.size();
        int i=0,j=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());       
        while(i<n && j<m) {
            if(a[i]<b[j])    i++;
            else if(b[j]<a[i])  j++;
            else { 
                //both elements are equal
                if(ans.size()==0 || ans.back()!=a[i]) //unique check
                    ans.push_back(a[i]); 
                i++;
                j++;
            }
        }
        return ans;
    }
};