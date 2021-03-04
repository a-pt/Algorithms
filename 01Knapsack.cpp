#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,gMax;
    cin>>n>>gMax;
    vector <int> w(n+1);
    vector <int> v(n+1);
    vector<vector <int>> dp(n+1,vector <int> (gMax+1,0));
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=gMax;j++)
        {
          dp[i][j]=dp[i-1][j];
          if(j-w[i]>=0)
                dp[i][j]=max(dp[i][j],v[i]+dp[i-1][j-w[i]]);
        }
    int ans=0,index=0;
    for(int j=0;j<=gMax;j++)
    {
        ans=max(ans,dp[n][j]);
        index=j;
    }
    cout<<ans<<" "<<index<<endl;
    vector <int> res(n+1,0);
    for(int i=n;i>0;i--)
    {
        if(dp[i][index]==dp[i-1][index])
            res[i]=0;
        else
        {
            res[i]=1;
            index-=w[i];
        }
    }
    for(int i=1;i<=n;i++)
        cout<<res[i]<<" ";
    return 0;
}
