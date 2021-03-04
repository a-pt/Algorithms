#include <iostream>
#include <vector>
#include <utility>;
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int left=1;left<=n;left++)
    {
        int right;
        for(right=left+1; right<=n && a[right-1]<a[right]; right++);
        right--;
        if(right==n)
        {
            ans=max(ans,n-left+1);
        }
        else{
          right++;
          if(right!=n && a[right-1]+1<a[right+1])
          {
            for(right=right+1;right<=n && a[right-1]<a[right];right++);
            right--;
          }
        ans=max(ans,right-left+1);
        }
    }
    cout<<ans;
    return 0;
}
