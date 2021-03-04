#include <iostream>

using namespace std;

int square[20][20];
void magicSquareDEven(int n)
{
    int index=1;
    int t=(n*n)+1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            square[i][j]=index;
            index++;
        }
    }
    for(int i=0;i<n/4;i++)
        for(int j=0;j<n/4;j++)
            square[i][j]=t-square[i][j];

    for(int i=0;i<n/4;i++)
        for(int j=3*(n/4);j<n;j++)
            square[i][j]=t-square[i][j];

    for(int i=3*(n/4);i<n;i++)
        for(int j=0;j<n/4;j++)
            square[i][j]=t-square[i][j];

    for(int i=3*(n/4);i<n;i++)
        for(int j=3*(n/4);j<n;j++)
            square[i][j]=t-square[i][j];

    for(int i=(n/4);i<3*(n/4);i++)
        for(int j=(n/4);j<3*(n/4);j++)
            square[i][j]=t-square[i][j];

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
    magicSquareDEven(order);
    return 0;
}
