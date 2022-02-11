class Solution {
//https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
public:
    int minimumLength(string &s) {
        int s_len = s.length();
        int i = 0, j = s_len - 1;
        
        while(s[i] == s[j] && i < j){
            i++,j--;
            while(i < s_len && s[i] == s[i-1])i++;
            if(i  > j)return 0;
            while(j >= 0 && s[j] == s[j+1])j--;
        }
        return j-i+1;
    }
};