class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
       int n=nums.size();
       int pref[100000]={0};
       int suff[100000]={0};
       int ckt=1;
       for(int i=1; i<n; i++){
           int prev=pref[i-1];
           pref[i]=prev+ckt*(nums[i]-nums[i-1]);
           ckt++;
       }
        ckt=1;
        for(int i=n-2; i>=0; i--){
            int next=suff[i+1];
            suff[i]=next+ckt*(nums[i+1]-nums[i]);
            ckt++;
        }
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i]=pref[i]+suff[i];
        }return ans;
    }
};