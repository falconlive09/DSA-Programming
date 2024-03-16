//{ Driver Code Starts
#include <iostream>
#include<list>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int josephus(int n, int k)
    {
       list<int>l; 
       for(int i=1;i<=n;i++)
            l.push_back(i);       
       auto it=l.begin();
       while(l.size()>1)
       {
            for(int count=1;count<k;count++)
            {
                it++;
                if(it==l.end())
                    it=l.begin();
            }
            it=l.erase(it);
            if(it==l.end()) //if next of the erase is end we shift it to beginning
                it=l.begin();
        }
        return l.front();
    }

};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends