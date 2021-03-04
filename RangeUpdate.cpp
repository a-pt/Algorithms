#include <iostream>
//Code not working in codeblocks but working in online GDB Compiler
using namespace std;
int a[100],b[100],s[100];
void update(int x,int y,int val)
{
    b[x]+=val;
    b[y+1]-=val;
}
void printarray(int n)
{
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+b[i];
        a[i]+=s[i];
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n,x,y,val,flag=0;
    cout<<"Enter n ";
    cin>>n;
    cout<<"Enter array ";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    do{
        cout<<"Enter x,y,val ";
        cin>>x>>y>>val;
        update(x,y,val);
        cout<<"Do you want to continue?(0/1) ";
        cin>>flag;
    }while(flag==1);

    printarray(n);

    return 0;
}
