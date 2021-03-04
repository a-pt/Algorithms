#include <iostream>

using namespace std;
int a[100],b[100];

void mergearr(int l,int mid, int r)
{
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=r)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(j<=r)
        b[k++]=a[j++];
    while(i<=mid)
        b[k++]=a[i++];
    for(int p=l;p<=r;p++)
        a[p]=b[p-l];
}


void mergesort(int l,int r)
{
    if(l+1==r)
    {
        if(a[l]>a[r])
        {
            int temp=a[r];
            a[r]=a[l];
            a[l]=temp;
        }
        return;
    }

    if(l==r)
        return;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    mergearr(l,mid,r);
}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergesort(0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i];
    return 0;
}
