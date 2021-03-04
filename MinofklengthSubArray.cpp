#include <iostream>
#include <utility>
#include <deque>
using namespace std;
int a[100];
int m[100];

void findans(int n,int k)
{
    deque <int> dq;
    for(int i=1;i<=n;i++)
    {
        while(!dq.empty() && a[dq.back()]>=a[i])
        dq.pop_back();
        dq.push_back(i);

        if(!dq.empty() && dq.front()<(i-k+1))
           dq.pop_front();
        if(i>=k)
        {
            m[i-k+1]=a[dq.front()];
        }
    }
}


int main()
{
    int n,k;
    cin>>n>>k;
    cout<<"Enter Array";
    for(int i=1;i<=n;i++)
        cin>>a[i];
    findans(n,k);
    for(int i=1;i<=n-k+1;i++)
        cout<<m[i]<<" ";
    return 0;
}
