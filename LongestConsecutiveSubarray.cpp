#include <iostream>

using namespace std;
int a[100],f[10];

int lcsa(int n)
{
    int res=0;
    for(int l=0;l<n;l++)
    {
        for(int k=0;k<10;k++)
                f[k]=0;
        int max_e=a[l];
        int min_e=a[l];
        for(int r=l;r<n;r++)
        {
            if(f[a[r]]==1)
            {
                break;
            }
            f[a[r]]++;
            if(min_e>a[r])
                min_e=a[r];
            else if(max_e<a[r])
                max_e=a[r];

            if((max_e-min_e)==(r-l))
                if((r-l+1)>res)
                    res=r-l+1;
        }
    }
    return res;
}

int main()
{
    int n;
    cout <<"Enter n :";
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<lcsa(n);
    return 0;
}
