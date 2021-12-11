#include <bits/stdc++.h>
using namespace std;
bool isValid(const string &s)
{
    // if (s[0] == ')' || s[0] == '}' || s[0] == ']')
    //     return false;
    stack<char> st;
    int i = 0;
    int n = s.length();
    while (i < n)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty()) 
				return false;
			if(s[i] == ')' && st.top() != '(')
				return false;
			if(s[i] == '}' && st.top() != '{')
				return false;
			if(s[i] == ']' && st.top() != '[')
				return false;
			st.pop(); 
        }
        i++;
    }
   return st.empty();
}
int main()
{
    string s;
    cin >> s;
    cout << isValid(s);
    stack<char> st;
    if (st.empty())
        cout << "its empty";
    return 0;
}