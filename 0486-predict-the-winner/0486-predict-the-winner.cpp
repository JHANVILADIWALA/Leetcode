class Solution {
public:
    int dp[21][21][2];
    int fn(int i, int j, int turn, vector<int> nums){
        //base case
        if(i>j)return 0;
        if(dp[i][j][turn]!=-1)return dp[i][j][turn];
        if(turn==0){ //turn of player 1
            int score1 = nums[i] + fn(i+1, j, 1 , nums); //take front one
            int score2 = nums[j] + fn(i, j-1, 1, nums);  //take end one
            return dp[i][j][turn]=max(score1, score2);                  //maximise score of player 1
        }
        else{ //player 2 turn
            int score1 = fn(i+1, j, 0 , nums);
            int score2 = fn(i, j-1, 0, nums);
            return dp[i][j][turn]=min(score1, score2); //minimise player2
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int total=0;
        for(int i=0; i<nums.size(); i++) total+=nums[i];
        memset(dp,-1, sizeof(dp));
        int score1 = fn(0, nums.size()-1, 0, nums);
        int score2 = total - score1;
        return score1>=score2;
    }
};