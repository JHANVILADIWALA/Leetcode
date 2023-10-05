class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto it:nums)m[it]++;
        vector<int>ans;
        int n=nums.size();
        n/=3;
        for(auto it:m){
            if(it.second>n)ans.push_back(it.first);
        }
        return ans;
    }
};