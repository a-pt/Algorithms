#include <iostream>

using namespace std;

int fastExpo(int a, long long n, int MOD)
{
    int ans=1;

    while(n>=1)
    {
        if(n%2==1)
        {
            ans=(ans*a*1LL)%MOD;
            n=n-1;
        }
        else
        {
            a=(a*a*1LL)%MOD;
            n=n/2;
        }
    }

    return ans;
}
int main()
{
    cout << fastExpo(7,0,1000000007) << endl;
    return 0;
}
