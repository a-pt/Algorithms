#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    vector <int> a(n+1);
    vector <int> dp(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        int c_max=1;
        for(int j=1;j<i;j++)
            if(a[i]>a[j])
            c_max=max(c_max,1+dp[j]);
        dp[i]=c_max;
        if(dp[i]>ans)
            ans=dp[i];
    }
    cout<<ans;
    return 0;
}
