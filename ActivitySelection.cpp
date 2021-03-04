#include <iostream>
#include <algorithm>
using namespace std;

struct obj
{
    int start;
    int finish;
    bool operator < (const struct obj& x)
    {
        return finish<x.finish;
    }
}a[101];

int main()
{
    int n;
    cin>>n;
    cout << "Enter activities :" << endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].start;
        cin>>a[i].finish;
    }
    sort(a+1,a+n+1);
    int act=0,c_fin=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i].start>=c_fin)
        {
            act++;
            c_fin=a[i].finish;
        }
    }
    cout<<act;
    return 0;
}
