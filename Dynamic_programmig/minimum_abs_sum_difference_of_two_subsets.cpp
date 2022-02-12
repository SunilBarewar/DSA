int minSubsetSumDifference(vector<int>& arr, int n)
{
//shorturl.at/npqQV
    int k = 0;
    for(auto x : arr)k+=x;
	 vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0] = curr[0] = true;
    if(arr[0] <= k)prev[arr[0]] = true;
    for(int ind = 1; ind < n;ind++){
        for(int target = 1; target <= k; target++){
               bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target)take = prev[target-arr[ind]];
            	curr[target] = take | notTake;
        }
        prev = curr;
    }
    
    int mini = 1e9;
    for(int s1 = 0; s1 <= k/2;++s1){
        if(prev[s1]){
            mini = min(mini,abs((k-s1) - s1));
        }
    }
    return mini;
}
