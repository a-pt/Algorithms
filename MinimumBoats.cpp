#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int n,w,b;
    cin>>n>>w>>b;
    vector <int> weight(n);
    vector <int> isTaken(n,0);
    for(int i=0;i<n;i++)
        cin>>weight[i];
    sort(weight.begin(),weight.end());
    priority_queue <pair<int,int>> pq;
    int p=0,ans=0;
    for(int i=n-1;i>=0;i--)
    {
        while(p<i && weight[p]+weight[i]<=w)
        {
            pq.push(make_pair(weight[p],p));
            p++;
        }
        if(isTaken[i]==1)
            continue;
        while(!pq.empty() && weight[i]-pq.top().first<=b)
        {
            if(isTaken[pq.top().second] || pq.top().second==i)
            {
                pq.pop();
                continue;
            }
            isTaken[i]=isTaken[pq.top().second]=1;
            pq.pop();
            break;
        }
        ans++;
    }
    cout<<ans;
    return 0;
}
