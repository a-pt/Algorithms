#include <iostream>
#include <cmath>
using namespace std;

int f[100],e[100],len;

void primeFact(int n)
{
    if(n==1)
    {
        f[len]=2;
        e[len]=0;
        len++;
        return;
    }
    int d=2;
    while(n>1 && d<=sqrt(n))
    {
        int k=0;
        while(n%d==0)
        {
            n/=d;
            k++;
        }
        if(k>0)
        {
            f[len]=d;
            e[len]=k;
            len++;
        }
        d++;
    }
    if(n>1)
    {
        f[len]=n;
        e[len]=1;
        len++;
    }
}


int main()
{
    int m;
    cout<<"Enter the number";
    cin>>m;
    primeFact(m);
    for(int i=0;i<len;i++)
    {
        cout<<f[i]<<" "<<e[i]<<endl;
    }
    cout<<"No of factors "<<len;
    return 0;
}
