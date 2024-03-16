#include <bits/stdc++.h> 
using namespace std;

long long int maximumNonAdjacentSum(vector<int> &nums){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n=nums.size();
    long long int prev=nums[0];
    long long int prev2=0;
    for(int i=0;i<n;i++){
        long long int take=nums[i];
        if(i>1) take+=prev2;
        
        int long long notTake=0+prev;
        int long long curi=max(take,notTake);
        prev2=prev;
        prev=curi;
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> temp1,temp2;
    int n=valueInHouse.size();
    if(n==1)    
        return valueInHouse[0];
    for(int i=0;i<n;i++){
        if(i!=0)    temp1.push_back(valueInHouse[i]);
        if(i!=n-1)  temp2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
}