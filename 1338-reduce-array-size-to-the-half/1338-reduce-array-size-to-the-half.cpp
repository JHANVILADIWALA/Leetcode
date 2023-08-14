class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int>pq;
        
        unordered_map<int,int>m;
        for(int i=0; i<arr.size(); i++)m[arr[i]]++;
        
        for(auto it:m) pq.push(it.second); 
        
        int ans=0;
        int orign=arr.size();
        int n=orign;
        
        while(n>orign/2){
            n-=pq.top();
            ans++;
            pq.pop();
        }
        return ans;
    }
};