#include<bits/stdc++.h>
using namespace std;

    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int carry = 0;
        for(int i = n-1; i>=0; i--){
            int sum = num[i] + k%10+carry;
            num[i] = sum%10;
            carry = sum/10;k /=10;
      }
      
          while (k!= 0)
          {
              int sum = k%10+carry;
              num.insert(num.begin(),sum%10);
              k /= 10;carry = sum / 10;
          }
        if(carry != 0){
            num.insert(num.begin(),carry);
        }cout<<k<<" "<<carry<<endl;
        return num;
    }
int main(){
    vector<int>num = {8};
    vector<int> ans = addToArrayForm(num,523);
    for(auto x : ans)cout<<x<<" ";
}