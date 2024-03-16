#include <iostream>
#include<list>

using namespace std;

int main()
{
    list<int>l;
    l.push_back(10);
    l.push_back(20);
    l.push_front(5);
    for(auto &x:l)
    {
        cout<<x<<" ";
    }
    cout<<"\n";

    list<int>l2={10,20,30,40,20,40};
    auto it=l2.begin();

    it=l2.erase(it);
    l2.remove(40);
    for(auto x:l2)
    {
        cout<<x<<" ";
    }
    
	return 0;
}