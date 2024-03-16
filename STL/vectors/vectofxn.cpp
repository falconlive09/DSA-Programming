#include <iostream>
#include<vector>

using namespace std;

void fun(const vector<int> &v)
{
    for(int x:v)
        cout<<x<<" ";
}
int main()
{
    //vector<int> v{5,7,8};
    //fun(v);
    vector<int> v2;
    v2.push_back(5);
    v2.push_back(10);
    v2.push_back(20);
    cout<<v2.size()<<" "<<v2.capacity()<<" "; //size is 3 but capacity of vector is 4
	return 0;
}