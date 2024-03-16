//Problem using vector of pairs
#include <iostream>
#include<vector>

using namespace std;

bool myCmp(pair<int,int>p1,pair<int,int>p2) //fxn made in order to sort acc to the decreasing order of marks
{
    return p1.second>p2.second;
}
void sortByMarks(int marks[],int roll[],int n)
{   
    vector<pair<int,int>>v; 
    for(int i=0;i<n;i++)
    {
        v.push_back({roll[i],marks[i]});
    }
    sort(v.begin(),v.end(),myCmp);
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second;
        cout<<"\n";
    }
}
int main()
{
    int roll[]={101,108,103,105};
    int marks[]={70,80,40,90};
    sortByMarks(marks,roll,(sizeof(marks)/sizeof(marks[0])));
    
    
	return 0;
}