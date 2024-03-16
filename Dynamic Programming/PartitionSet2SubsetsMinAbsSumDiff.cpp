#include <bits/stdc++.h> 
using namespace std;
 
int minSubsetSumDifference(vector<int>& arr, int n){
	int totSum=0;
	for (int i=0; i <n;i++){
		totSum+=arr[i];
	}
	//from subset sum equal to k (space optimised)
	int k=totSum;
	vector<bool> prev(k+1, 0), cur(k+1,0); //k columns only 1 row
    prev[0]=cur[0]=true;
    if(arr[0]<=k) //to prevent runtime error
        prev[arr[0]]=true; //at index 0
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool noTake=prev[target];
            bool take=false;
            if(target>=arr[ind])
                take=prev[target-arr[ind]];
            cur[target]=take || noTake;
        }
        prev=cur;
	}

	int mini=1e9;
	for(int s1=0;s1<=totSum/2;s1++){
		if(prev[s1]==true){
			mini=min(mini,abs(totSum-(2*s1)));
		}
	}
	return mini;
}