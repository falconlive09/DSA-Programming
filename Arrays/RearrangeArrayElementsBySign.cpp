#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int pos=0,neg=1;
        for(int i=0;i<n;++i) {
            if(nums[i]>0) {
                ans[pos]=nums[i];
                pos+=2;
            }
            else {
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};

//follow up
//no of positives!=no of negatives add the extras at end with altering the order

void rearrange(vector<int> &arr) {
	int n=arr.size();
	vector<int>pos,neg;
	for(int i=0;i<n;++i) {
		if(arr[i]>0) {
			pos.push_back(arr[i]);
		}
		else {
			neg.push_back(arr[i]);
		}
	}
	if(pos.size()>neg.size()) {
		for(int i=0;i<neg.size();++i) {
			arr[i*2]=pos[i];
			arr[2*i+1]=neg[i];
		}
		int ind=neg.size()*2;
		for(int i=neg.size();i<pos.size();++i) {
			arr[ind]=pos[i];
			++ind;
		}
 	}
	else {
		for(int i=0;i<pos.size();++i) {
			arr[i*2]=pos[i];
			arr[i*2+1]=neg[i];
		}
		int ind=pos.size()*2;
		for(int i=pos.size();i<neg.size();++i) {
			arr[ind]=neg[i];
			++ind;
		}
	}
}