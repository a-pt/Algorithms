#include <iostream>
#include <vector>
using namespace std;

void reconstruct(vector <vector <int>>& lcs,vector <char>& a,vector <char>& b,int m,int n)
{
   /* if(i==0 || j==0)
        return;
    if(a[i]==b[j])
    {
        reconstruct(lcs,a,b,i-1,j-1);
        cout<<a[i]<<" ";
    }
    else if(lcs[i-1][j]>lcs[i][j-1])
        reconstruct(lcs,a,b,i-1,j);
    else
        reconstruct(lcs,a,b,i,j-1);*/
    int index=lcs[m][n];
    char s[index+1];
    s[index]='\0';
    int i=m;
    int j=n;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            s[index]=a[i];
            i--;j--;index--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1])
        i--;
        else
        j--;
    }
    for(int i=1;i<=lcs[m][n];i++)
        cout<<s[i];
}


int main()
{
    int n,m;
    cin>>m>>n;
    vector <char> a(m+1);
    vector <char> b(n+1);
    vector <vector <int>> lcs(m+1,vector <int> (n+1,0));
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int j=1;j<=n;j++)
        cin>>b[j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
        if(a[i]==b[j])
            lcs[i][j]=1+lcs[i-1][j-1];
        else
            lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    cout<<lcs[m][n]<<endl;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
        {
            cout<<lcs[i][j]<<" ";
        }
        cout<<endl;
    }
    reconstruct(lcs,a,b,m,n);
    return 0;
}
