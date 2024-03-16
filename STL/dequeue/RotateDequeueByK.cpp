#include<iostream>
#include<deque>

using namespace std;
void left_Rotate_Deq_ByK()
{
    
}
void right_Rotate_Deq_ByK()
{

}
int main()
{
    int N,x;
    deque<int>dq;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>x;
        dq.push_back(x);
    }
    for(auto x : dq)
    {
        cout<<x;
    }
    right_Rotate_Deq_ByK();
    left_Rotate_Deq_ByK();
    
    
    
    return 0;
}