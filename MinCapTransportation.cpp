#include <iostream>

using namespace std;

int g[100];

int maxrides(long long s,int n)
{
    int rides=1;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=g[i];
        if(sum>s)
        {
            rides++;
            sum=0;
            i--;
        }
    }
    return rides;
}

int mincap(int n,int k)
{
    int cur,ma=g[0];
    long long tot=0,mid,ans=-1;
    for(int i=0;i<n;i++)
    {
        tot+=g[i];
        if(ma<g[i])
            ma=g[i];
    }
    long long l=ma;
    long long h=tot;
    while(l<=h)
    {
        mid=(h+l)/2;
        cur=maxrides(mid,n);
        if(cur<=k)
        {
            ans=mid;
            h=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>g[i];
    cout<<mincap(n,k);
    return 0;
}
