#include <iostream>

using namespace std;

//Given an array of natural no's, find largest subarray with atmost k distinct elements

int fr[11];
int a[100];

int LsubK(int n,int k)
{
    int cr,res,maxl=0;
    for(int l=0;l<n;l++)
    {
        for(int i=1;i<=10;i++)
            fr[i]=0;
        cr=k;
        res=0;
        for(int r=l;r<n;r++)
        {
            if(fr[a[r]]==0)
            {
            if(cr==0)
                break;
            else
            {
                cr--;
                fr[a[r]]=1;
            }
            }
            res++;
        }
        maxl=max(res,maxl);
    }
    return maxl;
}


int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<LsubK(n,k);
    return 0;
}
