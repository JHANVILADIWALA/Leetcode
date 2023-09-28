class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>v;
        // vector<int>even;
        vector<int>odd;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&1)odd.push_back(nums[i]);
            else v.push_back(nums[i]);
        }
        for(auto it:odd)v.push_back(it);
        return v;
    }
};