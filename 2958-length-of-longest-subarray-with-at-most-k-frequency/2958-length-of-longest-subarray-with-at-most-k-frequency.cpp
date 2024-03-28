class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int i=0, j=0;
        int n=nums.size();
        unordered_map<int,int>m;
        
        while(j<n){
            m[nums[j]]++;
            
            while(m[nums[j]]>k){
                m[nums[i]]--;
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
             
        }
        
        return ans;
    }
};