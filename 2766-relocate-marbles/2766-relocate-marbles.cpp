class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& mf, vector<int>& mt) {
        set<int>s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        for(int i=0 ; i<mf.size(); i++){
            s.erase(mf[i]);
            s.insert(mt[i]);
        }
        vector<int>ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};