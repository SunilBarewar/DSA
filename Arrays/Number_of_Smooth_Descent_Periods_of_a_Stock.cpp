#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    long long getDescentPeriods(vector<int>& p) {
        int n = p.size();
        p.push_back(INT_MAX);
        long long cnt = 0;
        int size = 0;
        for(int i = 1; i < n;i++){
            if(p[i-1] - p[i] == 1){
                size++;
                if(p[i] - p[i+1] != 1){
                      size++;
                cout<<"size : "<<size<<endl;
                long long posDays = ((size*(size+1))/2);
                posDays -=size;
                cnt += posDays;
                size = 0;
                }
            }
        }
        return cnt+n;
    }
};




int main(){
    int n ;cin>>n;
    vector<int>prices(n);
    for(int i = 0; i < n;i++)cin>> prices[i];

    Solution obj;
    cout<<obj.getDescentPeriods(prices);
    return 0;
}