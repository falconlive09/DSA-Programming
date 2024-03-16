#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> max_of_subarrays(int *arr, int n, int k){
        vector<int> ans;
        int i=0,j=0;   
        deque<int> l; //or we can use list<int> l
        while(j<n){
            while(l.size()>0 && l.back()<arr[j]){ //we don't need the smaller elements < j  
                l.pop_back();
            }
            l.push_back(arr[j]);
            if(j-i+1<k)
                j++;
            else if(j-i+1==k){
                //calculate max from the list
                ans.push_back(l.front()); //maximum at the front of the list
                if(l.front()==arr[i]) 
                    l.pop_front(); //remove the ith maximum as it won't be utilised in next sliding window
                i++;
                j++;
            }
        }
        return ans;
    }
};


int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
