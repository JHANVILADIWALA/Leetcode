class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto it: nums){
            m[it]++;}
        int ans=0;
        for(auto it:m){
            int val= it.second;
            val*=val-1;
            val/=2;
            ans+=val;}
        return ans;
    }
};