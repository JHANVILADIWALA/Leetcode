class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size()<3)return true;
        
        bool flg=false;
        for(int i=0; i<nums.size()-1; i++){
            int sum = nums[i] + nums[i+1];
            if(sum>=m)flg=true;
        }
        return flg;
    }
};