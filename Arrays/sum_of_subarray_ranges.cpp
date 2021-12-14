#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        // sort(nums.begin(),nums.end());
        for(int x : nums)cout<<x<<" ";cout<<endl;
        int n = nums.size();
        for(int i = 0; i< n;i++){
            int large = INT_MIN,small = INT_MAX;
            for(int j = i; j < n;j++){
                if(nums[j] < small) small = nums[j];
                if(nums[j] > large) large = nums[j];
                long long range  = large - small;
                sum+=range;
            }
        }//4,-2,-3,4,1
        return sum;
    }
};
int main(){
    Solution obj;
    vector<int>v = {4,-2,-3,4,1};
    cout<<obj.subArrayRanges(v);
}