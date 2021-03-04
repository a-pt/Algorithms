#include <iostream>
#include <vector>

using namespace std;
bool visited[500][500];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char a[500][500];

bool ok(int r,int c,int n,int m)
{
    if((r<n && 0<=r) && (c<m && 0<=c) && !visited[r][c] && a[r][c]=='.')
       return true;
    return false;
}

void fillalgo(int r,int c,int n,int m,int* p)
{
    visited[r][c]=true;
    (*p)++;
    for(int i=0;i<4;i++)
    {
        if(ok(r+dx[i],c+dy[i],n,m))
        {
            fillalgo(r+dx[i],c+dy[i],n,m,p);
        }
    }
}



int main()
{
    int n,m,ans=0,island=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ok(i,j,n,m))
            {
                island++;
                int counter=0;
                fillalgo(i,j,n,m,&counter);
                if(counter>ans)
                    ans=counter;
            }
        }
    }
    cout<<island<<" "<<ans<<endl;
    return 0;
}
