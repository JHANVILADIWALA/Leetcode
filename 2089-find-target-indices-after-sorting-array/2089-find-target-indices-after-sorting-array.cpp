class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int start=0, end=n-1;
        
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        ub--;
        cout<<lb<<" "<<ub<<endl;
        for(int i=lb; i<=ub; i++){
            ans.push_back(i);
        }
        
        return ans;
    }
};