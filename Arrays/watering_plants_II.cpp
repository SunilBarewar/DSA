
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int alice = 0 , bob = n-1;
        int filled = 0;
        int currA = capacityA , currB = capacityB;
        while (alice<=bob)
        {
            if(alice == bob){
                if(plants[alice] > currA && plants[bob]  > currB){
                    filled++; 
                }
                break;
            }
           if(plants[alice] > currA){
               filled++;
               currA  = capacityA;
           }currA -=plants[alice];

           if(plants[bob] > currB){
               filled++;
               currB  = capacityB;
           }currB -=plants[bob];

           alice++,bob--;
        }
        return filled;
    }
};
int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int  i = 0; i < n; i++){
        cin>>v[i];
    }
    int capacityA,capacityB;
    cin>>capacityA>>capacityB;
    Solution obj;
    cout<<obj.minimumRefill(v,capacityA,capacityB);
return 0;
}