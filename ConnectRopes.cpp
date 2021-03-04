#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long int minrope(vector <int> ropes)
{
    priority_queue <int> pq;
    long long int ans=0;
    for(int rope:ropes)
        pq.push(-rope);
    for(int step=1;step<ropes.size();step++)
    {
        int min1=-pq.top();
        pq.pop();
        int min2=-pq.top();
        pq.pop();
        cout<<min1<<" "<<min2<<endl;
        ans+=(min1+min2);
        pq.push(-(min1+min2));
    }
    return ans;
}
int main()
{

    int n;
    cin>>n;
    vector <int> a(n);
    cout << "Enter array: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<minrope(a);
    return 0;
}
