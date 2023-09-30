class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int alland=INT_MAX;
        for(auto it: nums){
            alland&=it;
        }
        if(alland!=0)return 1;
        
        int ckt=0;
        alland=INT_MAX;
        for(auto it: nums){
            alland&=it;
            if(alland==0){
                ckt++; alland=INT_MAX;
            }
        }
        return ckt;
    }
};