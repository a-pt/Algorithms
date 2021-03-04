#include <iostream>

using namespace std;


int square[15][15];

void magicSquareOdd(int n)
{
    int i,j;
    i=n/2;
    j=n-1;
    square[i][j]=1;
    int entry=1;
    int flag=0;
    while(entry<n*n)
    {
        if(flag==0)
        {
            i=i-1;
            j=j+1;
        }
        else
        {
            i=i+1;
            j=j-2;
        }
        if((i==-1)&&(j==n))
        {
            j=n-2;
            i=0;
        }
        else if(i==-1)
            i=n-1;
        else if(j==n)
            j=0;

        if(square[i][j]==0)
        {
            entry++;
            square[i][j]=entry;
            flag=0;
        }
        else
        {
            flag=1;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<square[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    int order;
    cin>>order;
    magicSquareOdd(order);
    return 0;
}
