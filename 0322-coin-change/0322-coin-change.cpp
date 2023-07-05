class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        
        // INITIALISATION :
        
        // INT_MAX .......
        // 0
        // 0
        // 0
        int n = coins.size();
        int t[n+1][sum+1];
        // 1st row -> its impossible ..need infinite coins to get sum from empty array
        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j==0)t[i][j]=0;
                if(i==0)t[i][j]=INT_MAX-1; // we are using INT_MAX-1 so it doesn't overflow
            }
        }
        
        //NOW INITIALISING 2nd ROW 
        // if(sum is divisible then its possible and we fill)
        // else its impossible
        for(int j=1; j<=sum; j++){
            if(j%coins[0]==0){
                t[1][j]=j/coins[0];
            }
            else{
                t[1][j]=INT_MAX-1;
            }
        }
        //....initialised
        
        // main code  : filling other blocks
        for(int i=2; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(coins[i-1]<=j){
                    int included = t[i][j-coins[i-1]] + 1 ;
                    int notincluded = t[i-1][j] ;
                    t[i][j] = min(included, notincluded);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        if(t[n][sum]==INT_MAX-1)return -1;
         return t[n][sum];
    }
};