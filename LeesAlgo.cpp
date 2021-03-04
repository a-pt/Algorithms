#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int a[100][100];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
int dist[100][100];
int leesalgo(int n,int m,pair <int,int> src, pair <int,int> dest)
{
    queue <pair<int,int>> q;
    dist[src.first][src.second]=1;
    q.push(src);
    while(!q.empty())
    {
        pair <int,int> cell=q.front();
        if(cell==dest)
            return dist[cell.first][cell.second]-1;
        for(int i=0;i<4;i++)
        {
            if(a[cell.first+dx[i]][cell.second+dy[i]]==1 && dist[cell.first+dx[i]][cell.second+dy[i]]==0)
            {
               q.push(make_pair(cell.first+dx[i],cell.second+dy[i]));
               dist[cell.first+dx[i]][cell.second+dy[i]]=dist[cell.first][cell.second]+1;
            }
        }
        q.pop();
    }
    return -1;
}

int main()
{
    pair <int,int> src,dest;
    int n,m;
    cin>>n>>m;
    cout<<"Enter Matrix"<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin>>a[i][j];
    cout<<"Source :";
    cin>>src.first>>src.second;
    cout<<"Destination :";
    cin>>dest.first>>dest.second;
    cout<<leesalgo(n,m,src,dest);
    return 0;
}
