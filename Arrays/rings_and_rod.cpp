#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        map<char,unordered_set<char>> mpp;
        int n = rings.size();
        for(int i = 1; i < n;i+=2){
            mpp[rings[i]].insert(rings[i-1]);
        }
        int cnt = 0;
        for(auto &it : mpp){
            unordered_set<char> s = it.second;
            if(s.size() == 3){
                cnt++;
            }
        }
        return cnt;
    }
};
int main(){
Solution obj;
    cout<<obj.countPoints("B0B6G0R6R0R6G9");
}