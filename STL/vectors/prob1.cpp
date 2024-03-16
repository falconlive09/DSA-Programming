#include <iostream>
#include<vector>

using namespace std;

vector <int> getsmall(vector <int> &v,int k)
{   
    vector<int> s;
    for(const int x:v)
    {
        if(x<k)
            s.push_back(x);
    }
    return s;
}
int main()
{
    vector<int> v{8,100,20,40,3,7};
    int k=10;
    vector<int> s=getsmall(v,k);
    for(int x:s)
    {
        cout<<x<<" ";
    }
    
	return 0;
}