class Solution {
    bool check(vector<int>&freq1,vector<int>freq2){
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i])return false;
        }
        return true;
    }
public:
// https://leetcode.com/problems/permutation-in-string/
    bool checkInclusion(string s1, string s2) {
        int len1  = s1.size();
        int len2  = s2.size();
        if(len1 > len2)return false;
        int i = 0,j;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for( j = 0; j < len1; j++){
            freq1[s1[j] - 'a']++;
            freq2[s2[j] -'a']++;
        }
        j--;
        while(true){
            if(check(freq1,freq2))return true;
            freq2[s2[i]-'a']--;
            i++,j++;
            if(j >= len2)return false;
            freq2[s2[j]-'a']++;
            
        }
        return false;
    }
};