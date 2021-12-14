#include<bits/stdc++.h>
using namespace std;

  vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        
        if((digits[n-1]+1) < 10){
            digits[n -1] =  digits[n-1]+1;
        }else{
            for(int i = n -1; i >=0; i--){
                int sum = digits[i-1]+1;
                digits[i] = sum %10;
                carry = sum /10;
                if(carry == 0)break;
            }
        }//9999 +1;
        if(carry != 0){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            else
                digits[i] = 0;
            
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main(){

}