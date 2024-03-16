#include <bits/stdc++.h>
using namespace std;

//Revisit
//2 Pointer
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ansSum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<abs(ansSum-target))
                    ansSum=sum;
                if(sum>target)
                    k--;
                else if(sum<target)
                    j++;
                else //equal one of the triplet
                    return target;
            }
        }
        return ansSum;
    }
};


//Check this out
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());//I am going to use Two pointer for that i'm sorting.
        int n=nums.size();

        int sum=nums[0]+nums[1]+nums[2];//Our Intial sum or assuption that intial three values are the closet sum
        for(int i=0;i<n-2;i++){ //n-2 Since we have taken n-1 in our point so no need to go beyond that
            //Implementing Two pointer technique
            int j=i+1;
            int k=n-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];//Temparory sum for comaprison
                if(abs(temp-target) < abs(sum-target) ) sum=temp;//if we find batter or closer sum then we update the above sum value
                if(temp>target){
                    k--;                  // if value is greater than target one just come one point right to left
                } else if(temp<target){
                    j++;             //if value is lower than target just come one point left to right 
                    
                }else return target;// if value already found no need to go for other just return 
            }
            
        }
        return sum;
    }
};