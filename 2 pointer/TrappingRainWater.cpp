#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //O(n) Space -> O(2*n)
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefixMax(n,-1e9);
        vector<int> suffixMax(n,-1e9);
        
        prefixMax[0]=height[0];
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1],height[i]);
        }

        suffixMax[n-1]=height[n-1]; 
        for (int j=n-2;j>=0;j--) {
            suffixMax[j]=max(suffixMax[j+1],height[j]);
        }

        int trap=0;
        for(int i=0;i<n;i++){
            trap+=min(prefixMax[i],suffixMax[i])-height[i];
        }
        return trap;
    }
};

//Optimal using 2 pointers
int trap(vector<int>& height) {  
    int n=height.size(); 
    int left=0,right=n-1;
    int res=0;
    int maxleft=0,maxright=0;
    while(left<=right){
        if(height[left]<=height[right]){
            if(height[left]>=maxleft) maxleft=height[left];
            else res+=maxleft-height[left];
            left++;
        }
        else{
            if(height[right]>=maxright) maxright= height[right];
            else res+=maxright-height[right];
            right--;
        }
    }
    return res;
}