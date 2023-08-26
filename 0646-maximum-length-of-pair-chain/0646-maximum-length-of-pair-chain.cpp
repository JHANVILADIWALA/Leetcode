class Solution {
public:
    int maxlen(vector<vector<int>>& pairs, vector<int>&dp, int i){
        if(i==pairs.size())return 0;
        if(dp[i]!=-1)return dp[i];
        
        //bs to get newstart
        int left=i+1, right=pairs.size()-1;
        int newstart=pairs.size();
        
        while(left<=right){
            int mid=left+(right-left)/2;
            if(pairs[i][1]<pairs[mid][0]){
                newstart=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        
        int pick = 1 + maxlen(pairs, dp, newstart);
        int notpick= maxlen(pairs, dp, i+1);
        
        return dp[i]=max(pick, notpick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
       sort(pairs.begin(), pairs.end());
       
        vector<int>dp(pairs.size(), -1);
        return maxlen(pairs, dp, 0);
    }
};