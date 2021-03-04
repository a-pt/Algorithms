#include <iostream>
#include <vector>
using namespace std;

int upperbound(vector <int>& mL,int a,int len)
{
    int l=1;
    int h=len;
    int m,ans=-1;
    while(l<=h)
    {
        m=(l+h)/2;
        if(mL[m]>a)
        {
            ans=m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    if (ans==-1)
        return len+1;
    else return ans;
}


int main()
{
    int n;
    cin>>n;
    vector <int> a(n+1);
    vector <int> dp(n+1);
    vector <int> mL(n+1);
    cout << "Enter Array" << endl;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    dp[1]=1;
    mL[1]=a[1];
    int len=1;
    for(int i=2;i<=n;i++)
    {
        int ub=upperbound(mL,a[i],len);
        dp[i]=ub;
        mL[ub]=a[i];
        len=max(len,dp[i]);
    }

    cout<<len;
    return 0;
}
