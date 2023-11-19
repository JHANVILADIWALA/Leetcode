class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
       int n=nums.size();
        int ckt=0;
        for(int i=n-1; i>=1; i--){
            if(nums[i]==nums[i-1])continue;
            ckt+=(n-i);
        }return ckt;
        
    }
};