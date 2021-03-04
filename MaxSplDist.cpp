#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;


bool isValid(vector<pair<int,int>> v,int dist)
{
    int p=-1,miny=1000000,maxy=-1000000;
    for(int j=1;j<v.size();j++)
    {
        while(p+1<j && v[j].first-v[p+1].first>=dist)
        {
            p++;
            if(v[p].second>maxy)
                maxy=v[p].second;
            if(v[p].second<miny)
                miny=v[p].second;
        }
        if(p!=-1 && abs(miny-v[j].second)>=dist)
            return true;

        if(p!=-1 && abs(maxy-v[j].second)>=dist)
            return true;

    }
    return false;
}



int binSearch(vector<pair<int,int>> v)
{
    sort(v.begin(),v.end());
    int l=0,h=1000000;
    int ans,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(isValid(v,mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            h=mid-1;
    }
    return ans;
}


int main()
{
    int n,x,y;
    cin>>n;
    vector<pair <int,int>> v;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    cout<<binSearch(v);
    return 0;
}
