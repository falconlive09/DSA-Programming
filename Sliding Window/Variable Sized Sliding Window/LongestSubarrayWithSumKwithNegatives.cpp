#include <bits/stdc++.h>
using namespace std;
int getLongestSubarray(vector<int> &a, int k){
    unordered_map<int,int> preSumMap;
    int sum=0;
    int maxLen=0;
    for(int i=0;i<a.size();++i) {
        sum+=a[i];
        if(sum==k) {
            maxLen=max(maxLen,i+1);
        }   
        int rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()) {
            int len=i-preSumMap[rem];
            maxLen=max(maxLen,len);
        }
        //condn. will work for postives and negatives
        if(preSumMap.find(sum)==preSumMap.end())
            preSumMap[sum]=i;
        //preSumMap[sum]=i; //only positives
    }
    return maxLen;
}