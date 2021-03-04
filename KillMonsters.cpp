#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> d(n);
    priority_queue <int> k;
    for(int i=0;i<n;i++)
        cin>>d[i];
    int m,kill=0;
    cin>>m;
    int x;
    cin>>x;
    for(int i=0;i<n;i++)
    {
        if(d[i]<=0)
        {
            x-=d[i];
            kill++;
        }
        else
        {
           if(x>0)
           {
               x-=d[i];
               kill++;
               k.push(d[i]);
           }
           if(x<=0)
           {
               if(m>0)
               {
                  m--;
                  int t=k.top();
                  k.pop();
                  x+=t;
               }
               else
               {
                   if(x<0)
                    kill--;
                   break;
               }
           }
        }
    }
    cout<<kill;
    return 0;
}
