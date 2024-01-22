class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        unordered_map<int,int>m;
        for(auto it: nums)m[it]++;
        
        int twice;
        for(auto it: m){
            if(it.second==2)twice=it.first;
        }
        
        int absent;
        for(int i=1; i<=n; i++){
        if(m.find(i)==m.end())absent=i;
    }
    vector<int>ans;
    ans.push_back(twice); ans.push_back(absent);
    
    return ans;
    }
};