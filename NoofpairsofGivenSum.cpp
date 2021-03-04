#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map <int,int> myMap;
    int n,s,val;
    cout << "Enter n,s ";
    cin>>n>>s;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>val;
        ans+=myMap[s-val];
        myMap[val]++;
    }
    cout<<ans;
    return 0;
}
