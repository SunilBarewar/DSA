//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1/#
class Solution
{
    void rev(int st , int end , string &s){
        while(st < end){
            char ch = s[st];
            s[st] = s[end];
            s[end] = ch;
            st++;end--;
        }
    }
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        int n = s.size();
        reverse(s.begin(),s.end());
        int st = 0;
        for(int i = 0; i< n;i++){
            if(s[i] == ' ' || s[i] =='.' ){
                rev(st,i-1,s);
                st = i+1;
            }
        }
         rev(st,n-1,s);
        return s;
    } 
};