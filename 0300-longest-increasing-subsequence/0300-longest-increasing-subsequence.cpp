class Solution {
public:
    int fn(int prevind, int currind, vector<int>& nums, vector<vector<int>>&m){
        if(currind>=nums.size())return 0;
        
        if(prevind !=-1 && m[prevind+1][currind+1]!=-1)return m[prevind+1][currind+1];
        
        //can pick
        if( prevind==-1 || nums[prevind]<nums[currind] ){
            int pick= 1 + fn(currind, currind+1, nums, m);
            int dontpick= fn(prevind, currind+1, nums, m);
            return m[prevind+1][currind+1]=max(pick, dontpick);
        }
        
        //cannot pick
        else{
            return m[prevind+1][currind+1]=fn(prevind, currind+1, nums, m);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>v(2502, vector<int>(2502, -1));
        return fn(-1, 0, nums, v);
    }
};