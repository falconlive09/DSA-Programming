//Problem using vector of pairs
#include <iostream>
#include<vector>

using namespace std;

void printSortwithIndex(int *arr,int n)
{   
    vector<pair<int,int>>v; 
    for(int i=0;i<n;i++)
    {
        v.push_back({arr[i],i});
    }
    sort(v.begin(),v.end()); //will sort acc to first element of pair
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second;
        cout<<"\n";
    }
}
int main()
{
    int arr[]={100,50,20};
    printSortwithIndex(arr,(sizeof(arr)/sizeof(arr[0])));
    
	return 0;
}