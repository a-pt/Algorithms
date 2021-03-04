#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    long long int n,len=0,index;
    cin>>n;
    vector <long long int> dp(n+1);
    vector <long long int> a(n+1);
    unordered_map <long long int,long long int> myMap;
    for(long long int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(myMap.find(a[i]-1)!=myMap.end())
        dp[i]=dp[myMap[a[i]-1]]+1;
        else
        dp[i]=1;
        if(myMap.find(a[i])==myMap.end())
            myMap[a[i]]=i;
        else
        {
            if(dp[i]>dp[myMap[a[i]]])
                myMap[a[i]]=i;
        }
        if(dp[i]>len)
        {
            len=dp[i];
            index=i;
        }
    }
    cout<<len<<endl;
    long long int element=a[index]-len+1;
    for(long long int i=1;i<=n;i++)
    {
        if(a[i]==element)
        {
          cout<<i<<" ";
          element++;
          if(element==a[index]+1)
            break;
        }
    }
    return 0;
}
