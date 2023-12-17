class Solution {
public:
    bool check(int div, vector<int>& nums, int th){
        int ans=0;
        for(auto it:nums){
            if(it%div==0)ans+=it/div;
            else ans+=it/div+1;
        }
        return ans<=th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //FFFFTTTT
        int l=1, r=1e9;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,nums,threshold)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};