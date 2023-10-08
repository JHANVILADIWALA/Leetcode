class Solution {
public:
    int fn(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&dp){
        if(i==nums1.size() || j==nums2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int a=fn(i, j+1, nums1, nums2, dp);
        int b=nums1[i]*nums2[j] + fn(i+1, j+1, nums1, nums2, dp);
        int c=fn(i+1, j, nums1, nums2, dp);
        return dp[i][j]=max(a, max(b,c));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int ans=fn(0,0,nums1,nums2,dp);
        
        //when one array is negative and other is positve
        if(ans==0){
            int a = *max_element(nums1.begin(), nums1.end());
            int b = *min_element(nums1.begin(), nums1.end());
           
            int c = *max_element(nums2.begin(), nums2.end());
            int d = *min_element(nums2.begin(), nums2.end());
           
           return max(a*d, b*c);
        }
        return ans;
    }
};