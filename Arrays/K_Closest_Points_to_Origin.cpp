#include<bits/stdc++.h>
using namespace std;
#define ll long long
class idx{
    public:
    ll distance;
    int index;
    idx(ll dis, int index){
        this->distance = dis;
        this->index = index;
    }
      bool operator< ( const idx otherStudent) const{
        return distance < otherStudent.distance;
    }
};
// struct compare{
//     bool operator()(idx a , idx b){
//         return a.distance < b.distance;
//     }
// };
class Solution {
    public :
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          int n = points.size();
        vector<idx>dist;
        vector<vector<int>>ans;
        // priority_queue<idx,vector<idx> , compare>pq;
        priority_queue<idx>pq;
        for(int i = 0; i < n;i++){
            // cout<<"endter";
            int x = points[i][0];
            int y = points[i][1];
            long long sum= pow(x,2) + pow(y,2);
            cout<<sum<<endl;
            // dist.push_back(idx(sum,i));

            if(pq.size() < k){
                pq.push(idx(sum ,i));
            }else{
                if(pq.top().distance > sum){
                    pq.pop();
                    pq.push(idx(sum ,i));
                }
            }
        }
        // for(auto x: distance)cout<<x<<" ";
        // for(int i = 0; i<n;i++){
        //     if(pq.size() < k){
        //         pq.push(dist[i]);
        //     }else{
        //         if(pq.top().distance > dist[i].distance){
        //             pq.pop();
        //             pq.push(dist[i]);
        //         }
        //     }
        // }
        while(!pq.empty()){
            int idx = pq.top().index;
            ans.push_back(points[idx]);
            pq.pop();
        }
        return ans;
    }
};
int main(){
    int n; cin>>n;
    int k ;cin>>k;
    vector<vector<int>> points(n,vector<int>(2));
    for(int i  = 0; i< n;i++){
        cin>>points[i][0]>>points[i][1];
    }
    // cout<<points.size()<<endl;
    Solution obj;
    vector<vector<int>> ans = obj.kClosest(points,k);
    for(auto &x : ans){
        cout<<x[0]<<" "<<x[1]<<endl;
    }
    cout<<pow(-2,2);
    return 0;
}