// Time Complexity: O(N! X N)
// Space Complexity: O(1)
class Solution {
private: 
    void solve( vector<int> nums,vector<vector<int>>&ans,int i ){
      if(i>=nums.size()){
         ans.push_back(nums);
         return;
      }
      for(int j=i;j<nums.size(); j++){
          swap(nums[j],nums[i]);
                solve(nums,ans,i+1);
          swap(nums[j],nums[i]);
      }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
       int i=0;
       solve(nums,ans,i);
    return ans;
    }
};