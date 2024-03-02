class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>v;
        for(auto it: nums){
            v.push_back(it*it);
        }
        sort(v.begin(), v.end());
        return v;
    }
};