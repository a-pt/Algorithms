#include <iostream>
#include <stack>

using namespace std;
int v[100];
int a[100][100];
long int findmaxhist(int b[],int m)
{
    stack <int> s;
    int right[100],left[100];
    for(int i=1;i<=m;i++)
    {
        right[i]=m+1;
        left[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        while(!s.empty() && b[s.top()]>b[i])
        {
            right[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    for(int i=m;i>0;i--)
    {
        while(!s.empty() && b[s.top()]>b[i])
        {
            left[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    long int area,maxarea=0;
    for(int k=1;k<=m;k++)
    {
        area=v[k]*(right[k]-left[k]-1);
        if(area>maxarea)
            maxarea=area;
    }
    return maxarea;
}

long int maxrect(int n,int m)
{
    long int maxarea=0,carea;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0)
            v[j]=0;
            else
            v[j]+=a[i][j];
        }
        carea=findmaxhist(v,m);
        if(carea>maxarea)
        {
            maxarea=carea;
        }
    }
    return maxarea;
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin>>a[i][j];
    cout<<maxrect(n,m);
    return 0;
}
