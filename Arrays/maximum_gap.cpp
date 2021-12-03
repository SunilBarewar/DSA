#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &v)
    {
        int n = v.size();
        if(n == 1) return 0;
        set<int> gap;
        int max_gap = 0;
        for (int i = 0; i < n; i++)
            gap.insert(v[i]);
        v.clear();
        for (int it : gap)
        {
            v.push_back(it);
        }
        n = v.size();
        for (int i = 1; i < n ; i++)
        {
            int temp = v[i] - v[i - 1];
            max_gap = max(max_gap, temp);
        }
        return max_gap;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // Solution obj;
    // cout<<obj.maximumGap(v);
    return 0;
}

/*
 // bucket sort
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        int n = nums.size();
        if (n < 2)
        	return 0;
        for (int i=0;i<n;++i) {
        	mn = min(nums[i], mn);
        	mx = max(nums[i], mx);
		}
		if (mx == mn)
			return 0;
		double bucket = (mx - mn + 0.0) / n; 
		vector<int> big(n, -1); 
		vector<int> small(n, -1);  
		for (int i=0;i<n;++i) {
			int index = (nums[i] - mn) / bucket;
			if (index >= n) 
				index = n - 1; 
			
			if (big[index] == -1) {
				big[index] = small[index] = nums[i];
			}
			else {
				big[index] = max(big[index], nums[i]);
				small[index] = min(small[index], nums[i]);
			}
		}
		int result = 0;
		int s = mn, b = mn;
		for (int i=0;i<n;++i) { 
			if (big[i] == -1)
				continue;
			result = max(small[i] - b, result); 
			s = small[i];
			b = big[i];
		}
		return result;
    }
};

*/