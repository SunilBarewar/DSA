#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int size = s.length();
        int maxLen = 0, len = 0, start = 1;

        set<char> letterSet;
        for (int i = 0; i < size; i++)
        {
            if (letterSet.find(s[i]) == letterSet.end())
            {
                letterSet.insert(s[i]);
                len++;
            }
            else
            {
                if (len > maxLen)
                    maxLen = len;
                letterSet.clear();
                i = start;
                start++;
                len = 0;
            }
        }
        if (len > maxLen)
            maxLen = len;
        return maxLen;
    }
    int lengthOfSubstring(string s)
    {
        int max_len = 0, l = 0, r = 0;
        int size = s.size();
        deque<char> ch;
        while (r < size)
        {
            if (find(ch.begin(), ch.end(), s[r]) == ch.end())
            {
                ch.push_back(s[r]);
                max_len = max(max_len, r - l + 1);
                r++;
            }
            else
            {
                ch.pop_front();
                l++;
            }
        }
        return max_len;
    }
    int lengthOfSubstring2(string s)
    {
        int max_len = 0, len = 0, i = -1, j = -1;
        int size = s.size();
        map<char, int> mpp;
        while (true)
        {
            bool flag1 = false;
            bool flag2 = false;

            while (i < size - 1)
            {
                i++;
                flag1 = true;
                mpp[s[i]]++;
                if (mpp[s[i]] == 2)
                    break;
                else
                {
                    len = i - j;
                    if (len > max_len)
                        max_len = len;
                }
            }

            while (j < i)
            {
                j++;
                mpp[s[j]]--;
                flag2 = true;
                if (mpp[s[j]] == 1)
                    break;
            }
            if (flag1 == false && flag2 == false)
                break;
        }
        return max_len;
    }
};
int main()
{
    string s;
    getline(cin, s);
    Solution obj;
    cout << obj.lengthOfSubstring2(s);
    return 0;
}