class Solution {
public:
    int fn(map< pair<int,int> , int >&dp, int prev, int i,vector<int>& arr1, vector<int>& arr2 ){
        if( i==arr1.size() ){//reached end
           return 0; //base case basically
        }
        if(dp.find({i,prev}) != dp.end() )return dp[{i,prev}];

        int ans=INT_MAX/2; // TO PREVENT OVERFLOW BZ IT HAPPENS TO BE +1

        //next higher number
        int id= upper_bound(arr2.begin(), arr2.end(),prev) - arr2.begin();

        //move on
        if(arr1[i]>prev) ans=min(ans, fn(dp,arr1[i],i+1,arr1,arr2));

        //replace
        if( id<arr2.size() ) ans= min(ans, fn(dp,arr2[id],i+1,arr1,arr2) +1);

        return dp[{i,prev}]=ans; 
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
         sort( arr2.begin(), arr2.end() );
         //        i   prev
         map< pair<int,int> , int >dp;
         //rec      dp   prev     i
         int ans= fn(dp, INT_MIN, 0, arr1, arr2);
         if(ans>=INT_MAX/2) return -1;
         else return ans;
    }
};