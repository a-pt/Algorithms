#include <iostream>

using namespace std;

int gcd(int a,int b)
{
    if(a>b){
        int t;
        t=a;
        a=b;
        b=t;
    }
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int gcdArray(int arr[],int l)
{
    int result=arr[0];
    for(int i=1;i<l;i++)
    {
        result=gcd(arr[i],result);
        if(result==1)
            return 1;
    }
    return result;
}

int lcmArray(int arr[],int l)
{
    int result=arr[0];
    for(int i=1;i<l;i++)
    {
        result=(arr[i]*result)/gcd(arr[i],result);
    }
    return result;
}
int main()
{
    int arr[10];
    int n;
    cout<<"Enter Length:";
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<gcdArray(arr,n)<<endl;
    cout<<lcmArray(arr,n)<<endl;
    return 0;
}
