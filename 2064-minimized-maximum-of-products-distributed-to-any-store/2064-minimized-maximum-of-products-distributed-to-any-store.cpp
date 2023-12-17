class Solution {
public:
    bool check(int mid, vector<int>&nums, int k){
        // 3   4   5   6 
        // 11  10  7   7
        int ckt=0;
        for(auto it:nums){
            if(it%mid==0)ckt+=it/mid;
            else ckt+=it/mid+1;
        }
        return ckt<=k;
        
        // 2  3  4  5
        // 9  6  5  5
        
    }
    int minimizedMaximum(int n, vector<int>& nums) {
         //FFFFTTTT
        int l=1, r=1e9;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,nums,n)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};