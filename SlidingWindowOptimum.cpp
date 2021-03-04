#include <iostream>

using namespace std;
int a[100];
int f[11];

int optLsubK(int n,int k)
{
    int x=0,y=0;
    int res=0;
    int max_r=-1,l=0,cr=k;
    for(int r=0;r<n;r++)
    {
        if(cr==0)
        {
            if(f[a[r]]>0)
            {
                f[a[r]]++;
                max_r++;
            }
            else
            {
                r--;
                if(res<=(max_r-l+1))
                {
                    y=max_r;
                    x=l;
                    res=(max_r-l+1);
                }

                f[a[l]]--;
                if(f[a[l]]==0)
                {
                    cr++;
                }
                l++;
            }
        }
        else
        {
            f[a[r]]++;
            max_r++;
            cr--;
        }
    }
    cout<<x<<" "<<y<<endl;
    return res;
}



int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<optLsubK(n,k);
    return 0;
}
