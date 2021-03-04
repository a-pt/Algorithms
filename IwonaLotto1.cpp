#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set <int> sum;
    int n,s,a[100],flag=0,temp;
    cout << "Enter n,s";
    cin>>n>>s;
    cout << "Enter the array ";
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                sum.insert(a[i]+a[j]+a[k]);
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                unordered_set <int> :: iterator it;
                it=sum.find(s-a[i]-a[j]-a[k]);
                if(it!=sum.end())
                {
                    temp=s-a[i]-a[j]-a[k];
                    cout<<a[i]<<" "<<a[j]<<" "<<a[k];
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            break;
    }
    if(flag==0)
        cout<<"Not Possible";
    else{
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    if(a[i]+a[j]+a[k]==temp)
                    {
                        cout<<" "<<a[i]<<" "<<a[j]<<" "<<a[k];
                        return 0;
                    }
    }


    return 0;
}
