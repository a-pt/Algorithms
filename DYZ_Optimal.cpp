#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> a(n+2,0);
    vector <int> maxLeft(n+1,0);
    vector <int> maxRight(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        if(i==2 || a[i-2]>=a[i-1])
            maxLeft[i]=1;
        else
            maxLeft[i]=maxLeft[i-1]+1;
    }
     for(int i=n-1;i>=0;i--)
    {
        if(i==n-1 || a[i+2]<=a[i+1])
            maxRight[i]=1;
        else
            maxRight[i]=maxRight[i+1]+1;
    }
    for(int p=2;p<=n;p++)
    {
        ans=max(ans,maxRight[p]+1);
        ans=max(ans,maxLeft[p]+1);
        if(a[p+1]-a[p-1]>=2)
            ans=max(ans,maxLeft[p]+maxRight[p]+1);
    }
    cout<<ans;
    return 0;
}
