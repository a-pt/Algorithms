#include <iostream>
#include <deque>
using namespace std;
int a[100];
int p[100];

int maxlen(int n,int A,int B)
{
    int maxsum=0;
    deque <int> dq;
    for(int i=0;i<=n-A;i++)
    {

    if(!dq.empty() && dq.front()<i-B)
        dq.pop_front();
    if(i>=A)
    {
        maxsum=max(maxsum,p[i+A]-p[dq.front()]);
    }
    while(!dq.empty() && p[dq.back()]>=p[i])
    {
        dq.pop_back();
    }
    dq.push_back(i);
    }
    return maxsum;
}


int main()
{
    int n,A,B;
    cin>>n;
    cout << "Enter array ";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=a[i]+p[i-1];
    }
    cout<<"Enter a,b ";
    cin>>A>>B;
    cout<<maxlen(n,A,B);
    return 0;
}
