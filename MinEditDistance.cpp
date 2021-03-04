#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int c1,c2,c3;
    cin>>c1>>c2>>c3;
    int n=s1.size();
    int m=s2.size();
    vector <vector<int>> dp(n+1,vector<int> (m+1));
    for(int j=0;j<=m;j++)
        dp[0][j]=j*c1;
    for(int i=0;i<=n;i++)
        dp[i][0]=i*c2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=c1+dp[i][j-1];
            dp[i][j]=min(dp[i][j],c2+dp[i-1][j]);
            dp[i][j]=min(dp[i][j],c3+dp[i-1][j-1]);
            if(s1[i-1]==s2[j-1])
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
        }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }

    cout<<dp[n][m];
    return 0;
}
