#include <bits/stdc++.h>
using namespace std;
    // checking can we place k cows with given distance
    bool canPlaceCows(vector<int> &arr, int cows, int distance)
    {
        int currPos = arr[0];
        int cnt = 1;

        for (int i = 1; i < arr.size(); i++)
        {

            if ((arr[i] - currPos) >= distance)
            {
                cnt++;
                currPos = arr[i];
            }
            if (cnt == cows)
                return true;
        }
        return false;
    }
    int aggresiveCows(vector<int> &arr, int cows)
    {
        // sort array if given array in not sorted
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if (cows == 2)
            return arr[n - 1] - arr[0];
        int lo = 1;
        int hi = arr[n - 1] - 1;
        int ans = 0;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (canPlaceCows(arr, cows, mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return ans;
    }
int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        int cows;
        cin >> cows;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        ans = aggresiveCows(arr, cows);
        cout << ans << endl;
    }
    return 0;
}