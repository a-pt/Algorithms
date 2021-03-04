#include <iostream>

using namespace std;
int s[11][11],a[11][11],ma;

void maxso(int n,int m)
{
    int mi;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]==1)
            {
                if(s[i][j-1]<=s[i-1][j] && s[i][j-1]<=s[i-1][j-1])
                mi=s[i][j-1];
                else if(s[i-1][j]<=s[i-1][j-1])
                mi=s[i-1][j];
                else
                mi=s[i-1][j-1];
                s[i][j]=1+mi;
            }
            if(s[i][j]>ma)
                ma=s[i][j];
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            s[i][j]=a[i][j];
        }

    maxso(n,m);
    cout<<ma;
    return 0;
}
