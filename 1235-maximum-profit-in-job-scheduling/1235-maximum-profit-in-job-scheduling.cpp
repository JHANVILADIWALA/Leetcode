class Solution {
public:
    int maxpro(vector<vector<int>>& arr, vector<int>&dp, int i){
        if(i==arr.size())return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        //bs
        int l=i+1, r=arr.size()-1;
        int newstart=arr.size();
        
        while(l<=r){
            int mid=l+(r-l)/2;
            // start     
            if(arr[mid][0] >= arr[i][1]){
                newstart=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        int pick=arr[i][2]+maxpro(arr,dp,newstart);
        int notpick=maxpro(arr,dp,i+1);
        
        return dp[i]=max(pick, notpick);
        
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>arr;
        int n=startTime.size();
        for(int i=0; i<n; i++){
            arr.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(arr.begin(), arr.end());
        
        vector<int>dp(arr.size(), -1);
        return maxpro(arr,dp,0);
    }
};