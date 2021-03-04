#include <iostream>

using namespace std;
int a[10][10],b[10],r1,c1,r2,c2,maxv;

void maxarray(int m,int i,int j)
{
    int sum=0,index=1;
    int maxc=b[1];
    int x=1;
    int y=1;
    for(int l=1;l<=m;l++)
    {
        sum+=b[l];
        if(maxc<sum)
        {
            maxc=sum;
            y=l;
            x=index;

        }
        if(sum<0)
        {
            sum=0;
            index=l+1;
        }

    }
    if(maxv<maxc)
    {

        c1=x;
        c2=y;
        r1=i;
        r2=j;
        maxv=maxc;
    }
}

void maxsubmat(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            b[j]=0;
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
                b[k]+=a[j][k];
            maxarray(m,i,j);
        }
    }
}
int main()
{
    int n,m;
    cout << "Enter order ";
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    maxv=a[1][1];
    maxsubmat(n,m);
    for(int i=r1;i<=r2;i++)
    {
        for(int j=c1;j<=c2;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    cout<<maxv;
    return 0;
}
