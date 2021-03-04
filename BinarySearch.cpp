#include <iostream>

using namespace std;
int a[30];
int binarysearch(int t,int l,int h)
{
    int m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(a[m]>t)
            h=m-1;
        else if(a[m]<t)
            l=m+1;
        else if(a[m]==t)
            return m;
    }
    return -1;
}
int main()
{
    int n,t;
    cin>>n;
    cout << "Enter array ";
    for(int i=1;i<=n;i++)
    cin>>a[i];
    cout<<"Enter Target ";
    cin>>t;
    cout<<binarysearch(t,1,n);
    return 0;
}
