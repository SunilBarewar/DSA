#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int n = strs.size();
        bool flag = true;
        for(int i = 1; i < n;i++){
            string str ="";
            for(int j = 0; j < ans.length(); j++){
                if(ans[j] == strs[i][j]){
                    flag = false;
                    str+=ans[j];
                }
                else{
                    ans = str;
                    break;
                }
                if(flag)return "";
            }
        }
        return ans;
    }
};
int main(){
    int n;cin>>n;
    vector<string>strs;
    for(int i = 0; i <n;i++){
        string s ;cin>>s;
        strs.push_back(s);
    }
    Solution obj;
    cout<<obj.longestCommonPrefix(strs);
    return 0;
}