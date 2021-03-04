#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const int N=666013,x=13;
vector <pair <string,int>> h[N];
int hash_key(string s)
{
    int l=s.size(),key=0;
    for(int i=0;i<l;i++)
        key=(key*x+s[i])%N;
    return key;
}

void add(string s)
{
    int key=hash_key(s);
    for(auto &x:h[key])
    {
        if(x.first==s)
        {
            x.second++;
            return;
        }

    }
    h[key].push_back(make_pair(s,1));
    return;
}

int counts(string s)
{
    int key=hash_key(s);
    for(auto x:h[key])
        if(x.first==s)
            return x.second;
    return 0;
}
int main()
{
    int n;
    string s,t;
    cout << "Enter no ";
    cin>>n;
    cout<<"Enter Strings :"<< endl;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        add(s);
    }

    cout<<"Enter target :"<<endl;
    cin>>t;
    cout<<counts(t);
    return 0;
}
