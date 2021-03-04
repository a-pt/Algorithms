#include <iostream>

using namespace std;

int getval(int n,int x, int y)
{
    if(n==0)
        return 1;
    if((x<=1<<(n-1)) && (y<=1<<(n-1)))
        return getval(n-1,x,y);
    else if ((x<=1<<(n-1)) && (y>1<<(n-1)))
        return (1<<(2*n-2)+getval(n-1,x,(y-1<<(n-1))));
    else if((x>1<<(n-1)) && (y<=1<<(n-1)))
        return 2*(1<<(2*n-2))+getval(n-1,x-1<<(n-1),y);
    else
        return 3*(1<<(2*n-2))+getval(n-1,x-1<<(n-1),y-1<<(n-1));
}

int main()
{
    int n;
    int x,y,f=0;
    do
    {
    cin>>n>>x>>y;
    cout<<getval(n,x,y);
    cin>>f;
    }while(f!=1);


    return 0;
}
