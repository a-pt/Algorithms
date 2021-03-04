#include <iostream>

using namespace std;
const int Nmax=1000;
int freq[Nmax];

void pegionhole(int n)
{
    int current_rem=0;

    for(int i=1;i<=n;i++)
    {
        current_rem=(current_rem*10+1)%n;//Don't store number as it take lot of excecution time. Take only remainder.
        if(current_rem==0)
        {
            for(int k=0;k<i;k++)
            cout<<1;
            return;
        }
        if(freq[current_rem]!=0)
            {
                for(int k=1;k<=i-freq[current_rem];k++)
                cout<<1;
                for(int k=1;k<=freq[current_rem];k++)
                cout<<0;
                cout<<endl;
                return;
            }
        freq[current_rem]=i;
    }
}

int main()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;
    pegionhole(n);
    return 0;
}
