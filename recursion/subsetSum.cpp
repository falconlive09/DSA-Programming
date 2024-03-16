#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    void subsetCalc(int ind,int sum,vector<int> &arr,int N,vector<int>&subsetSum)
    {
        //Time Complexity-> O(2^n)+ Sorting O((2^n)log(2^n))
        //Space Complexity-> 2^n (As subsets are given by 2^n where n are the number of elements in a set)
        if(ind==N)
        {
            subsetSum.push_back(sum);
            return;
        }
        
        //picking up the element
        subsetCalc(ind+1,sum+arr[ind],arr,N,subsetSum);

        //do not pick the element and not add to the sum
        subsetCalc(ind+1,sum,arr,N,subsetSum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>subsetSum;
        subsetCalc(0,0,arr,N,subsetSum);
        sort(subsetSum.begin(),subsetSum.end()); //if sorted output they want
        return subsetSum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends