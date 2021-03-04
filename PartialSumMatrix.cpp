#include <iostream>

using namespace std;
int a[100][100];
int s[100][100];
void precompute(int m,int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
        cin>>a[i][j];
        s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cout<<s[i][j]<<" ";
        cout<<endl;
    }

}

int sum(int l1,int c1,int l2,int c2)
{
    return (s[l2][c2]-s[l1-1][c2]-s[l2][c1-1]+s[l1-1][c1-1]);
}
int main()
{
    int l1,c1,l2,c2,m,n;
    cin>>n>>m;
    precompute(m,n);
    int flag=1;
    while(flag==1)
    {
    cout<<"Enter index:";
    cin>>l1>>c1>>l2>>c2;
    cout << sum(l1,c1,l2,c2)<<endl;
    cin>>flag;
    }
    return 0;
}
