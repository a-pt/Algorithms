#include <iostream>

using namespace std;
int maxleftsum(int a[],int left,int mid)
{
    int sum=0,maxsum=a[mid];
    for(int l=mid;l>=left;l--)
    {
        sum+=a[l];
        if(maxsum<sum)
            maxsum=sum;
    }
    return maxsum;
}

int maxrightsum(int a[],int mid,int right)
{
    int sum=0,maxsum=a[mid+1];
    for(int r=mid+1;r<=right;r++)
    {
        sum+=a[r];
        if(maxsum<sum)
            maxsum=sum;
    }
    return maxsum;
}
int maxsumsubarray(int a[],int left,int right)
{
    if(left==right)
        return a[left];
    int mid=(left+right)/2;
    int p,q,ans,r;
    p=maxsumsubarray(a,left,mid);
    q=maxsumsubarray(a,mid+1,right);
    if(p>q)
        ans=p;
    else
        ans=q;
    r=maxleftsum(a,left,mid)+maxrightsum(a,mid,right);
    if(ans<r)
        ans=r;
    return ans;
}


int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxsumsubarray(a,0,n-1);
    return 0;
}
