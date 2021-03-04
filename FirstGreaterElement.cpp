#include <iostream>
#include <stack>

using namespace std;

int ans[100];
stack <int> s;

void firstgreater(int a[],int n)
{
    for(int i=1;i<=n;i++)
    {
        while(!s.empty() && a[s.top()]<a[i])
        {
                ans[s.top()]=i;
                s.pop();
        }
        s.push(i);
    }
}

int main()
{
    int n,a[100];
    cout << "Enter array" << endl;
    cin>>n;
    cout<<"Enter Elements"<<endl;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    firstgreater(a,n);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
