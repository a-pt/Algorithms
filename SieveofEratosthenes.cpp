#include <iostream>


using namespace std;
const int Nmax=10001;
bool isPrime[Nmax];

void SofE(int limit)
{
    for(int i=2;i<=limit;i++)
        isPrime[i]=true;
    for(int i=2;i<=limit/2;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*2;j<=limit;j+=i)
                isPrime[j]=false;
        }
    }

}

int main()
{
    int n;
    cout<<"Enter limit ";
    cin>>n;
    SofE(n);
    for(int i=2;i<=n;i++)
        if(isPrime[i])
            cout<<i<<endl;
    return 0;
}
