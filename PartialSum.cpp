#include <iostream>

using namespace std;
int a[100];
int s[100];
void precomp(int arr[],int n)
{
    s[0]=a[0];
    for(int i=1;i<n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
}
long long query(int x,int y)
{
    int res=s[y]-s[x-1];
    return res;
}
int main()
{
    int n,x,y;
    cout<<"Enter n ";
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    precomp(a,n);
    cout<<"Enter x and y ";
    cin>>x>>y;
    cout<<query(x,y);
    return 0;
}
