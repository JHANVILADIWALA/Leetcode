class Solution {
public:
    int maximumCount(vector<int>& nums) {
        //find lower bound of 0
        // lb--
        //find upper bound of 0
        int n = nums.size();
        int lb = lower_bound(nums.begin(), nums.end(),0)-nums.begin();
        lb--;
        int neg = max(0,lb+1);
        int ub = upper_bound(nums.begin(), nums.end(),0)-nums.begin();
        int pos = max(0, n-ub);
        
        return max(pos,neg);
    }
};