#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int &n, const int &x) {
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else    
            low=mid+1;
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int &n, int &m){
    //'n' rows 'm' columns
    int count_max=0;
    int ind=-1;
    for(int i=0;i<n;i++){
        int cnt_ones=m-(lower_bound(matrix[0].begin(),matrix[0].end(),1)-matrix[0].begin());
        if(cnt_ones>count_max){
            count_max=cnt_ones;
            ind=i;
        }
    }
    return ind;
}