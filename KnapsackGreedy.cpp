#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct wv
{
    int weight;
    double vpu;
    bool operator <(struct wv& b)
    {
    return vpu>b.vpu;
    }
};

int main()
{
    long int ans=0;
    int n,c,val,wt;
    cout<<"Enter N and C: ";
    cin>>n>>c;
    vector <wv> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>val;
        cin>>wt;
        v[i].weight=wt;
        v[i].vpu=(double)val/wt;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        cout<<v[i].vpu<<":"<<v[i].weight<<" ";
    }

    cout<<endl;
    for(int i=0;i<=n && c>0;i++)
    {
        int u=min(v[i].weight,c);
        ans+=v[i].vpu*u;
        c-=u;
    }
    cout<<ans;
    return 0;
}
