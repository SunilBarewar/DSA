#include<bits/stdc++.h>
using namespace std;

class Solution {

    public :
    vector<vector<string>> PalindromePar(string &s){
        vector<string>path;
        vector<vector<string>>res;
        solve(s,0,path,res);
        // print(res);
        return res;
    }
    private:
    void solve(const string &s, int idx, vector<string>&path,vector<vector<string>>&res){
        //
        if(idx == s.size()){
            res.push_back(path);
            return;
        }
        for(int i = idx; i< s.size(); i++){
            if(isPalindrome(s,idx,i)){
                path.push_back(s.substr(idx, i - idx+1));
                solve(s,i+1,path,res);
                path.pop_back();
            }
        }
    }
    public:
    bool isPalindrome(const string &s, int st, int end){
        while(st < end){
            // cout<<s[st]<< " "<<s[end]<<endl;
            if(s[st] != s[end])return false;
            st++;
            end--;
        }
        return true;
    }
    void print(vector<vector<string>>&res){
        for(auto& v : res){
            for(auto &str : v){
                cout<<str<<"   ";
            }cout<<endl;
        }
    }
};
int main(){
    string s;cin>>s;
    Solution obj;
    vector<vector<string>>res = obj.PalindromePar(s);
    obj.print(res);
//    cout<<obj.isPalindrome("opno",0,3);

    return 0;
}