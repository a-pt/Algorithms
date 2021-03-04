#include <iostream>
#include <stack>

using namespace std;
int typeof(char c)
{
    if(c=='}' || c=='{')
        return 1;
    if(c=='[' || c==']')
        return 2;
    else
        return 3;
}


int valid(string s)
{
    stack <int> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            st.push(s[i]);
        else
        {
            if(st.empty())
                return 0;
            else if(typeof(s[i])==typeof(st.top()))
                st.pop();
        }
    }
    return st.empty();
}


int main()
{
    string s;
    cout << "Enter String" << endl;
    cin>>s;
    cout<<valid(s);
    return 0;
}
