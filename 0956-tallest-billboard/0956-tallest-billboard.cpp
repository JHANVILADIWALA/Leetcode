class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum=0;  //calculate sum of all rods
        for( int rod : rods){
            sum += rod;
        }

        int dp[sum+1];  // stores the max hts of billboards for diff sums (sum are indices)
        dp[0]=0;   // sum 0 has ht 0
        for(int i=1;i<=sum ;i++){
            dp[i]=-1; //means we dont know currently
        }
        
        for(int rod: rods){   //for every rod
            int dpcopy[sum+1];  //create copy to avoid overwriting
            
            //    start  end       to
            copy( dp, dp+(sum+1), dpcopy);
            //copied dp to dpcopy
            
            for(int i=0; i<=sum; i++ ){ // iterate from 0 to sum
                if( dpcopy[i]<0 )continue;  //means this is not achievable.. so skip iteration
                
                // achievable -> 2 steps
                dp[i+rod]= max(dp[i+rod], dpcopy[i]);
                
                dp[ abs(i-rod) ]= max(dp[ abs(i-rod) ], dpcopy[i]+ min(i,rod) ); // bridge gap
            }
            
        }
        return dp[0];
        
    }
};