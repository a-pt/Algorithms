#include <iostream>

using namespace std;
bool valid(int a[],int x,int k,int n)
{
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        if(x<a[i])
            s+=x;
        else
            s+=a[i];
    }
    if(s>=(x*k))
        return true;
    else
        return false;
}

int maxgroup(int a[],int n,int k)
{
    int group=1,mid;
    int l=1;
    long long t=0;
    for(int i=1;i<=n;i++)
        t+=a[i];
    int h=t/k;

    while(l<=h)
    {
     mid=(l+h)/2;
     if(valid(a,mid,k,n))
     {
         group=mid;
         l=mid+1;
     }
     else
        h=mid-1;
    }
    return group;
}




int main()
{
    int a[100],n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<< maxgroup(a,n,k);
    return 0;
}
