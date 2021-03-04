#include <iostream>
//Working in other IDE
using namespace std;

int a[11][11],b[11][11],c[11][11];

void update(int l1,int c1,int l2,int c2,int val)
{
    b[l1][c1]+=val;
    b[l1][c2+1]-=val;
    b[l2+1][c1]-=val;
    b[l2+1][c2+1]+=val;
}

void partialsum(int n,int m)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            c[i][j]=b[i][j]+c[i-1][j]+c[i][j-1]-c[i-1][j-1];
}

int main()
{
    int l1,c1,l2,c2,val,n,m,flag=1;
    cout<<"Enter order ";
    cin>>n>>m;
    cout<<"Enter matrix"<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin>>a[i][j];
    while(flag==1)
    {
        cout << "enter index and values ";
        cin>>l1>>c1>>l2>>c2>>val;
        update(l1,c1,l2,c2,val);

        partialsum(n,m);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            cout<<c[i][j]+a[i][j]<<" ";
        cout<<endl;
        }
        cin>>flag;
    }
    return 0;
}
