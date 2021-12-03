#include <bits/stdc++.h>
using namespace std;
vector<int> helper;

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    if (target == 0)
    {
        vector<vector<int>> base;
        base.push_back(helper);
        return base;
    }
    else if (target < 0)
    {
        vector<vector<int>> base;
        return base;
    }

    vector<vector<int>> ans;
    for (int i = 0; i < candidates.size(); i++)
    {
        helper.push_back(candidates[i]);
        vector<vector<int>> temp = combinationSum(candidates, target - candidates[i]);
        if (!temp.empty())
        {
            
            ans.push_back(temp[0]);
        }
        helper.pop_back();
    }
    return ans;
}

void print(vector<vector<int>> &arr)
{
    for (vector<int> &v : arr)
    {
        for (int &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int target;
    cin >> target;
    vector<vector<int>> ans = combinationSum(v, target);
    print(ans);
    return 0;
}