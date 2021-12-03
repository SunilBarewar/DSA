
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int currCapacity = capacity;
        int n = plants.size() ;
        for(int i = 0; i < n;i++){
            if(plants[i] > currCapacity){
                currCapacity = capacity;
                steps += (2*i);
            }
            currCapacity -= plants[i];
        }
        return steps + n;
    }
};

int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int  i = 0; i < n; i++){
        cin>>v[i];
    }
    int capacity;cin>>capacity;
    Solution obj;
    cout<<obj.wateringPlants(v,capacity);
return 0;
}