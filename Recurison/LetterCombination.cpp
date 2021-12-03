#include <bits/stdc++.h>
using namespace std;

vector<string> codes = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution
{
    public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        helper2(ans, digits);
        return ans;
    }

    // without using any codes array

    void helper2(vector<string> &ans, string digits, string p = "")
    {
        if (digits.length() == 0)
        {
            ans.push_back(p);
            return;
        }

        int digit = digits[0] - '0';
        int start = (digit - 2) * 3;
        int end = (digit - 1) * 3;
        // edge cases
        if (digit == 7)
        {
            end++;
        }
        else if (digit == 8)
        {
            start++;
            end++;
        }
        else if (digit == 9)
        {
            start++;
            end += 2;
        }

        for (int i = start; i < end; i++)
        {
            char ch = 'a' + i;
            helper2(ans, digits.substr(1), p + ch);
        }
    }
    void helper(vector<string> &ans, string digits, string p = "")
    {
        if (digits.length() == 0)
        {
            ans.push_back(p);
            return;
        }

        int index = digits[0] - '0';
        string code = codes[index];
        int n = code.length();

        for (int i = 0; i < n; i++)
        {
            helper(ans, digits.substr(1), p + code[i]);
        }
    }
};

int main()
{
    string digit;
    cin >> digit;
    Solution obj;
    vector<string> ans = obj.letterCombinations(digit);
    for(auto &i : ans){
        cout<<i<<" ";
    }
    return 0;
}