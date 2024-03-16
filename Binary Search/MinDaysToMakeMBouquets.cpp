#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int> &bloomDay,int &day,int &m,int &k){ 
        int count=0;
        int noOfBouquets=0;
        for(int i=0;i<bloomDay.size();i++){
            if(day>=bloomDay[i]){
                count++;
            }
            else{
                noOfBouquets+=(count/k);
                count=0; 
            }
        }
        if(count>0){
            noOfBouquets+=(count/k);
        }
        if(noOfBouquets>=m)
            return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n < (m * 1LL * k * 1LL) ) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(!possible(bloomDay,mid,m,k)){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};