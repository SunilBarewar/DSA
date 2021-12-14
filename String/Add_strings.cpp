#include<bits/stdc++.h>
using namespace std;
string add_strings(string num1,string num2){
    if(num1[0] == '0')return num2; 
    if(num2[0] == '0')return num1; 
    int l1 = num1.length();
    int l2 = num2.length();
    vector<int>arr((max(l1,l2)+2),0);
    int n =arr.size()-1;
    int carry = 0;
    int k = n - 1;
    for(int i = l1 -1,j  = l2 -1; j>=0 || i>=0;i--,j--){
        int ival = i>=0 ? num1[i] -'0':0;
        int jval = j>=0 ? num2[j] -'0':0;
        int sum = ival+jval+carry;
        carry = sum/10;
        arr[k] = sum % 10;
        k--;
    }
    if(carry != 0){
        arr[k] = carry;
    }cout<<n<<endl;
    string ans ="";
    bool flag = false;
    for(int i = 0; i < n;i++){
        if(arr[i] == 0 && flag == false)continue;
        else flag = true, ans.push_back(arr[i]+'0');
    }
    return ans;
}

int main(){
    string num1,num2;
    // cin>>num1>>num2;
    // cout<<add_strings(num1,num2); 
    string s = "sunil";
    string * ptr = &s;
    cout<<*ptr<<endl;
    cout<<ptr[0];
    return 0;
}