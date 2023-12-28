class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0;
        int i=0;
        int n=nums.size();
        int maxi=0;
        set<int>s;
        
        for(int j=0; j<n; j++){
            while(s.find(nums[j])!=s.end()){
                s.erase(nums[i]); 
                sum-=nums[i];
                i++;
            }
            s.insert(nums[j]);
            sum+=nums[j];
            maxi=max(maxi, sum);
        }
        return maxi;
        
    }
};