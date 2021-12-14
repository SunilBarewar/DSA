#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int maxSubArray(vector<int>& arr) {
        int curr = 0;
        int ans = INT_MIN;
        int n = arr.size();
        if(n == 1 && arr[0] <= 0)return arr[0];
        for(int i = 0; i< n;i++){
            curr +=arr[i];
            if(curr < 0)curr = 0;
            ans = max(ans,curr);
        }
        if(curr == 0 &&ans == 0)ans = *max_element(arr.begin(),arr.end());
        return ans;
    }
    

};
int main()
{
 int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution obj;
    cout << obj.maxSubArray(v);

    return 0;
return 0;
}