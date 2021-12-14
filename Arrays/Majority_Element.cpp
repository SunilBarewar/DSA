#include <bits/stdc++.h>
using namespace std;
/*
The majority element is the element that appears more than ⌊size/ 2⌋ times. You may assume that the majority element always exists in the array.
*/
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {   int n = nums.size();
        for(int i = 0; i < n;i++){
            int cnt = 1;
            for(int j = i+1; j < n;j++){
                if(nums[i] == nums[j])
                cnt++;
            }
            if(cnt > n/2)return nums[i];
        }
        return -1;
    }
    //  Moore's Voting Algorithm 
    int MooreAlgo(vector<int> &nums)
    {   int n = nums.size();
        int candidate = nums[0];
        int vote = 1;

        for(int  i = 0; i < n;i++){
            if(candidate == nums[i])vote++;
            else{
                vote--;
                if(vote == 0){
                    candidate = nums[i];
                    vote = 1;
                }
            }
        }
        return candidate;
    }
};
int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    Solution obj;
    cout<<obj.majorityElement(v);
    return 0;
}