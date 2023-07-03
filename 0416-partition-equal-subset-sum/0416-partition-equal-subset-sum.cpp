class Solution {
public:
    bool isSubsetSum(vector<int>arr, int sum){
         int n = arr.size();
         bool t[n+1][sum+1];
         
         //initialisation
         // T F F F F  ...
         // T
         // T
         // T
         for(int i=0; i<=n; i++){
             for(int j=0; j<=sum; j++){
                 if(i==0)t[i][j]=false;
                 if(j==0)t[i][j]=true;
             }
         }
         
         for(int i=1; i<=n; i++){
             for(int j=1; j<=sum; j++){
                 if( arr[i-1]<=j ){
                     //pick or not pick
                     t[i][j] =  t[i-1][j-arr[i-1]] ||  t[i-1][j]  ;
                 }
                 else{
                     //can't pick
                     t[i][j]= t[i-1][j];
                 }
             }
         }
         return t[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        //get total sum
        // if odd -> can never be divided ->return false
        // else ->check if its possible to get subset with sum as sum/2
        
        int sum=0;
        int n = nums.size();
        for(int i=0; i<n; i++) sum+=nums[i];
        
        if( sum%2!=0 ) return false;
        else{
            if( isSubsetSum(nums, sum/2 )==true )return true;
            else return false;
        } 
        
    }
};