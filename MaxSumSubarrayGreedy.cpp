#include <iostream>

using namespace std;
int a[100];
void maxsum(int n)
{
    int sum=0;
    int maxsum=a[0];
    int x=0,y=0,index=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];

        if(maxsum<sum)
        {
            maxsum=sum;
            y=i;
            x=index+1;
        }
        if(sum<0)
        {
            sum=0;
            index=i;
        }
    }
    cout<<maxsum<<" "<<x<<" "<<y<<endl;
}

int main()
{
    int n;
    cout << "Enter n ";
    cin>>n;
    cout << "Enter array ";
    cout<< endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    maxsum(n);
    return 0;
}
