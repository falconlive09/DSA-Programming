#include <iostream>
#include<forward_list>

using namespace std;

int main()
{
    forward_list<int>l={10,15,20};
    l.push_front(5);
    l.push_front(3);
    l.pop_front();
    for(int &x:l)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    forward_list<int>l2;
    l2.assign(l.begin(),l.end());
    for(int &x:l)
    {
        cout<<x<<" ";
    }
	return 0;
}