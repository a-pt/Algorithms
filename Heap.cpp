#include <iostream>

using namespace std;
int a[100],n;
void upheap(int pos)
{
    int i=pos;
    while(i>1 && a[pos]>a[pos/2])
    {
        swap(a[pos],a[pos/2]);
        pos/=2;
    }
}
void add(int ele)
{
    a[++n]=ele;
    upheap(n);
}
void downheap(int pos)
{
    int larger=pos;
    if(pos*2<=n && a[pos*2]>a[larger])
        larger=pos*2;
    if((pos*2+1)<=n && a[pos*2+1]>a[larger])
        larger=pos*2+1;
    if(pos!=larger)
    {
        swap(a[pos],a[larger]);
        downheap(larger);
    }
}

int maxdel()
{
    int m=a[1];
    a[1]=a[n--];
    downheap(1);
    return m;
}

int main()
{
    int ele;
    cin>>n;
    cout<<"Enter array";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<"Element to insert :";
    cin>>ele;
    add(ele);
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"Maximum ele"<<maxdel()<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
