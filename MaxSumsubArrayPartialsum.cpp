#include <iostream>

using namespace std;
int a[100];
int s[100];
void partialsum(int n)
{
    s[0]=a[0];

    int min_index=0,maxsum=s[0],sum,x=0,y=0;
    for(int i=1;i<n;i++)
    {
        s[i]=s[i-1]+a[i];
        sum=s[i]-s[min_index];
        if(sum>maxsum)
        {
            maxsum=sum;
            x=min_index+1;
            y=i;
        }
        if(s[min_index]>s[i])
        {
            min_index=i;
        }
    }
    cout<<maxsum<<" "<<x<<" "<<y;
}

int main()
{
    int n;
    cout << "Enter n ";
    cin>>n;
    cout<<"Enter array :"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    partialsum(n);
    return 0;
}
