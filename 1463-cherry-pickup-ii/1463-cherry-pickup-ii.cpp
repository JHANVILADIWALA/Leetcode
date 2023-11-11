class Solution {
public:
    int dp[71][71][71];
    int fn(vector<vector<int>>& grid, int r, int c1, int c2){
        
        //base case......................................//
        
        //not possible
        if(r>=grid.size() || c1<0 || c2<0 || c1>=grid[0].size() || c2>=grid[0].size()){
        return INT_MIN;
    }
        //only possible way
        if(r==grid.size()-1){
            if(c1==c2)return grid[r][c1];
            else return grid[r][c1]+grid[r][c2];
        }
        //...............................................//
        
        if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
        
        //current call
        int cherry=0;
        if(c1==c2)cherry+=grid[r][c1];
        else cherry+=(grid[r][c1]+grid[r][c2]);
        
        //further calls
        int maxcherry=0;
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                maxcherry=max(maxcherry, fn(grid, r+1, c1+i, c2+j));
            }
        }
        //return current call+further calls answer
        return dp[r][c1][c2]=maxcherry+cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        
        return fn(grid,0,0,m-1);
    }
};