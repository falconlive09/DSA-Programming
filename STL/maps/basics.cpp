#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{
    
    map<int,int> m;
    vector<int>nums{1,1,1,2,2,3};
    for(int i=0;i<nums.size();i++)
    {
        m[nums[i]]++;
    }
    for(auto it=m.begin();it!=m.end();it++)
    
    /*
    m.insert({10,200});
    m[5]=100;
    m.insert({3,100});
    for(auto &x:m)
    {
        cout<<x.first<<" "<<x.second<<" ";
    }
    */
    return 0;
}