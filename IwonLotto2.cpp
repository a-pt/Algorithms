#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n,s,a[100];
    unordered_map <int,vector <int>> triplet;
    cout << "Enter n,s ";
    cin>>n>>s;
    cout<<"Enter array"<<endl;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
              triplet[a[i]+a[j]+a[k]]={i,j,k};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
            {
                int temp=s-a[i]-a[j]-a[k];
                if(triplet.find(temp)!=triplet.end())
                {
                    vector <int> v= triplet[temp];
                    cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[v[0]]<<" "<<a[v[1]]<<" "<<a[v[2]];
                    return 0;
                }

            }
    cout<<"Not Possible";
    return 0;
}
