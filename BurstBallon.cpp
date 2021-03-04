#include <iostream>
#include <vector>
using namespace std;


int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+2);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        arr[0]=1;
        for(int i=1;i<=n;i++)
            arr[i]=nums[i-1];
        arr[n+1]=1;
        for(int left=n;left>=1;left--)
        {
            for(int right=left;right<=n;right++)
            {
                if(left==right)
                    dp[left][right]=arr[left-1]*arr[left]*arr[right+1];
                else
                {
                int maxp=0,cp;
                for(int k=left;k<=right;k++)
                {
                    cp=arr[k]*arr[right+1]*arr[left-1];
                    if(k>left)
                        cp+=dp[left][k-1];
                    if(k<right)
                        cp+=dp[k+1][right];
                    maxp=max(maxp,cp);
                }
                dp[left][right]=maxp;
                }
            }
        }
        return dp[1][n];
}

int main()
{
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout << maxCoins(v) << endl;
    return 0;
}
