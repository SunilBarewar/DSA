#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int MaxProduct(vector<int> &arr)
    {
        int curr = 1;
        int maxProduct = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            curr *= arr[i];//-2 3 -4
            maxProduct = max(maxProduct, curr);
            if(curr == 0)curr = 1;
        }
        curr = 1;
        for (int i = n-1; i >=0; i--)
        {
            curr *= arr[i];
            maxProduct = max(maxProduct, curr);
            if(curr == 0)curr = 1;//3,-1,4
        }
        return maxProduct;
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
    cout << obj.MaxProduct(v);

    return 0;
}