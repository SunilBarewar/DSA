#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val)   
        int n = nums.size();
        int cnt = 0;
        int last = 0;
        for(int i = 0; i< n;i++){
            if(nums[i] == val){
                cnt++;
              continue;
            }

            nums[last] = nums[i];last++;
        }
    }
};

int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i = 0; i<n ;i++)cin>>nums[i];
    Solution obj;
    int k ;cin>>k;
    cout<<obj.removeElement(nums,k)<<endl;
}