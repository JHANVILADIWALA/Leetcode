class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq; //{dist,{x,y}}
        
        for(auto it: points){
            int x=it[0];
            int y=it[1];
            
            
            long long val=x*x+y*y; 
            pq.push({val,{x,y}});
        }
        while(k--){
            vector<int>v;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            v.push_back(x);
            v.push_back(y);
            ans.push_back(v);
        }
        return ans;
    }
};