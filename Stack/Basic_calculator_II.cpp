#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.length();
        char sign = '+';
        for(int i = 0; i< n;i++){
            char ch = s.at(i);
            if(isdigit(ch)){
                int val = 0;
                while (i < n && isdigit(s[i]))
                {
                    int digit = s[i] - '0';
                    cout<<digit<<" ";
                    val = val * 10 + digit;
                    i++;
                }i--;
                // cout<<"val : "<<val<<endl;
                if(sign == '+'){
                    st.push(val);
                }else if(sign == '-'){
                    st.push(-val);
                }else if(sign == '*'){
                    int a = st.top();
                    st.pop();
                    int ans = a * val ;
                    st.push(ans);
                }else if(sign =='/'){
                    int a = st.top();
                    st.pop();
                    int ans = a / val ;
                    st.push(ans);
                }
            }
            else if(ch != ' '){
                sign = ch;
            }
        }
        int sum = 0;
        while (!st.empty())
        {
            // cout<<st.top()<<endl;
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
int main(){
    Solution obj;
    string s;
    getline(cin,s);
    cout<<obj.calculate(s)<<endl;
    // int d  = '2' - '0';
    // cout<<d;
    return 0;
}