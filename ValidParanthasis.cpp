#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    if (s.size() % 2 != 0)
    {
        cout << "NO" << endl;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                cout << "NO" << endl;
            }
            if (s[i] == ')')
            {
                if (st.top() != '(')
                {
                    cout << "NO" << endl;
                }
                else
                {
                    st.pop();
                }
            }
            else if (s[i] == '}')
            {
                if (st.top() != '{')
                {
                    cout << "NO" << endl;
                }
                else
                {
                    st.pop();
                }
            }
            else if (s[i] == ']')
            {
                if (st.top() != '[')
                {
                    cout << "NO" << endl;
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    if (st.empty())
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}
