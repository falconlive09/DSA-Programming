#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.size()<<"\n";
    cout<<s.top()<<"\n";
    s.pop();
    cout<<s.top()<<"\n";
    
    return 0;
}