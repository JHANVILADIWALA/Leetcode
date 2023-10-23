class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int result=nums[0];
        vector<int>t=nums;
        
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0],0});
        
        for(int i=1; i<nums.size(); i++){
            
            while(!pq.empty() && i-pq.top().second>k)pq.pop();
            
            t[i]=max(t[i], nums[i]+pq.top().first);
            result=max(result, t[i]);
            
            pq.push({t[i], i});
        }
        return result;
    }
};