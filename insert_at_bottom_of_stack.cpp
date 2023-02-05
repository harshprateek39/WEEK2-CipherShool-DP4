#include <bits/stdc++.h>
using namespace std;

stack<int> insrtAtTop(stack<int> &st, int x)
{
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    return st;
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(6);
    s.push(11);
    s.push(22);
    s.push(21);
    s.push(42);
    int k = 34;
    stack<int> ans = insrtAtTop(s, k);
    while (!ans.empty())
    {
        cout << ans.top()<<" ";
        ans.pop();
    }
}