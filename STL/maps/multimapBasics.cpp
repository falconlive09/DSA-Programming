#include<iostream>
#include<map>

using namespace std;

int main()
{
    
    multimap<int,int> mp;
    mp.insert({10,5}); mp.insert({50,1});
    mp.insert({20,3}); mp.insert({20,2});
    
    for(auto &x:mp)
    {
        cout<<x.first<<" "<<x.second<<" "<<endl;
    }
    cout<<"Lower & Upper Bound Functions"<<"\n";
    auto it1=mp.lower_bound(20);
    auto it2=mp.upper_bound(20);
    cout<<(*it1).first<<endl;
    cout<<(*it2).first<<endl;
    
    return 0;
}