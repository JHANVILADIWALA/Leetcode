class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans;
        for(int i=0;i<n;i++){
            if(m[nums[i]]==1) {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};