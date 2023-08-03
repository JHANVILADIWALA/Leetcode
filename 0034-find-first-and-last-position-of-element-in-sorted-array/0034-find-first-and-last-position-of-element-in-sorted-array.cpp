class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>ans(2);
        ans[0]=-1; ans[1]=-1;
        
        int lb= lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int ub= upper_bound (nums.begin(), nums.end(), target)-nums.begin();
        ub--;
        
        cout<<lb<<" "<<ub<<endl;
        if(lb!=nums.size() && ub!=nums.size() && ub>=lb){
            ans[0]=lb;
            ans[1]=ub;
        }
        return ans;
    }
};