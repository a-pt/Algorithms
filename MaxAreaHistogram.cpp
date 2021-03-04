#include <iostream>
#include <vector>
#include <stack>

using namespace std;
long long int maxhist(vector <int> a)
{
    int n=a.size();
    stack <int> s;
    vector <int> left(n,-1);
    vector <int> right(n,n);
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && a[s.top()]>a[i])
        {
            right[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    s.pop();
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && a[s.top()]>a[i])
        {
            left[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    long long int area,maxarea=a[1];
    for(int k=0;k<n;k++)
    {
        area=(right[k]-left[k]-1)*a[k]*1LL;
        if(area>maxarea)
            maxarea=area;
    }
    return maxarea;
}
int main()
{
    vector <int> a;
    int n,val;
    cin>>n;
    cout << "Enter heights :" << endl;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        a.push_back(val);
    }
    cout<<maxhist(a);
    return 0;
}
