#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int calculate(string s)
    {
        stack<char> st;
        int n = s.length();
        int sum = 0;
        char sign = '+';
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' && sign == '-')
            {
                while (s[i] != ')')
                {
                    if( s[i] != '(' && s[i] != ' ' )
                    st.push(s[i]);
                }
                char oprator = '+';
                int a ,b; 
                int cal = 0;
                while(!st.empty()){
                    if(isdigit(st.top())){

                    }
                }
            }
            else if (isdigit(s[i]))
            {
                int val = 0;
                while (i < n && isdigit(s[i]))
                {
                    int digit = s[i] - '0';
                    val = val * 10 + digit;
                    i++;
                }i--;
                if (sign == '+')
                    sum += val;
                else
                    sum -= val;

                cout << "sum : " << sum << endl;
            }
            else
            {
                if (s[i] == '+' || s[i] == '-')
                    sign = s[i];
            }
        }
        return sum;
    }
};
int main()
{
    string s;
    getline(cin, s);
    Solution obj;
    cout << obj.calculate(s);
    // int n = -33;
    // n = -n;
    // cout<<n;
    return 0;
}

/*

                if (isdigit(s[i]))
                    {
                        int digit = s[i] - '0';
                        if (prevSign == '+')
                        sum -= digit;
                        else
                        sum += digit;
                    } 
                    else if (s[i] == '+' || s[i] == '-')
                    prevSign = s[i];

                    if(s[i +1] == '('){
                        break;
                    }
                    i++;

*/