#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool greatest(pair<double,char>& a,pair<double,char>& b)
{
    if(a.first!=b.first)
        return a.first<b.first;
    else
        return a.second>b.second;
}
int minplatforms(vector <pair<double,char>> &time)
{
    int ans=0,fp=0;
    for(pair <double,char> p:time)
    {
        if(p.second=='D')
        {
            fp++;
        }
        else
        {
            if(fp==0)
                ans++;
            else
                fp--;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    double v1,v2;
    vector <pair<double,char>> time;
    cout<<"Enter array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v1;
        time.push_back(make_pair(v1,'A'));
        cin>>v2;
        time.push_back(make_pair(v2,'D'));
    }
    sort(time.begin(),time.end(),greatest);

    cout<<minplatforms(time);
    return 0;
}
