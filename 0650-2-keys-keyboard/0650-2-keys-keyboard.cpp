class Solution {
public:
    int dp[1001][1001];
    
    int solve(int cb, int aos, int n){
        if(aos>n)return 100000000;
        if(aos==n)return 0;
        if(aos==0)return 1+solve(aos,aos,n);
        
        if(aos==cb)return 1+solve(aos, aos+cb, n);
        
        int copy=solve(aos,aos,n);
        int paste=solve(cb,aos+cb,n);
        return 1+min(copy,paste);
    }
    int minSteps(int n) {
        if(n==1)return 0;
        
        return 1+solve(1,1,n);
    }
};